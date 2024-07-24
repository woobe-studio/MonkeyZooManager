#include "space_modify.h"
#include "ui_space_modify.h"

#include "scripts.h"

#include <QMessageBox>

SpaceModify::SpaceModify(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::SpaceModify)
{
    ui->setupUi(this);

    setMinimumSize(360, 640);
    resize(360, 640);

    connect(ui->TypeComboBox, &QComboBox::currentTextChanged, this, &SpaceModify::on_TypeComboBox_currentIndexChanged);
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    settingValues(zoo);
}

SpaceModify::~SpaceModify()
{
    delete ui;
}

void SpaceModify::on_DeleteButton_clicked()
{
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    if (zoo->getSpaceCount() != 0) {
        if (zoo->getSpace(currentAreaIndex)->isEmpty()) {
            QMessageBox::StandardButton reply = QMessageBox::question(
                this, "Delete Zoo Area",
                "Are you sure you want to delete this empty area?",
                QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                zoo->removeSpace(zoo->getSpace(currentAreaIndex));
                QMessageBox::information(this, "Delete Zoo Area", "Delete Successful");
            }
        }
        else {
            QMessageBox::StandardButton reply = QMessageBox::question(
                this, "Delete Zoo Area",
                "Are you sure you want to delete this area?",
                QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                zoo->removeSpace(zoo->getSpace(currentAreaIndex));
                QMessageBox::information(this, "Delete Zoo Area", "Delete Successful");
            }
        }
    }
    else {
        QMessageBox::warning(this, "Delete Zoo Area", "There are no Zoo Areas to delete.");
    }
    ui->IntegerValue->setText("");
    // Handle delete button click
}


void SpaceModify::on_CreateButton_clicked() {
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    QString area_capacity_text = ui->IntegerValue->text();
    if (area_capacity_text.isEmpty()) {
        QMessageBox::warning(this, "Create Zoo Area", "Please set capacity of the area.");
    }
    else {
        int area_capacity = area_capacity_text.toInt();
        if (area_capacity < 1) {
            QMessageBox::warning(this, "Create Zoo Area", "New capacity will not hold any animal inside. Please set the value correctly.");
        }
        else {
            QMessageBox::StandardButton reply = QMessageBox::question(
                this, "Create Zoo Area",
                "Are you sure you want to create this area?",
                QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                std::string area_name = ui->TypeComboBox->currentText().toStdString();
                if (area_name == "Cage") {
                    Monkey::Cage* new_space = new Monkey::Cage;
                    zoo->addSpace(new_space);
                    new_space->setCapacity(area_capacity);
                }
                else if (area_name == "Hospital") {
                    Monkey::Hospital* new_space = new Monkey::Hospital;
                    zoo->addSpace(new_space);
                    new_space->setCapacity(area_capacity);
                }
                else if (area_name == "Enclosure") {
                    Monkey::Enclosure* new_space = new Monkey::Enclosure;
                    zoo->addSpace(new_space);
                    new_space->setCapacity(area_capacity);
                }
                QMessageBox::information(this, "Create Zoo Area", "Create Successful");
            }
        }
    }
    ui->IntegerValue->setText("");
}

void SpaceModify::on_EditButton_clicked()
{
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    if (zoo->getSpaceCount() != 0) {
        QString area_capacity_text = ui->IntegerValue->text();
        if (area_capacity_text.isEmpty()) {
            QMessageBox::warning(this, "Edit Zoo Area", "Please set capacity of the area.");
        }
        else {
            int area_capacity = area_capacity_text.toInt();
            if (area_capacity < zoo->getSpace(currentAreaIndex)->getCapacity()) {
                QMessageBox::warning(this, "Edit Zoo Area", "New capacity is smaller than a current one.");
            }
            else {
                QMessageBox::StandardButton reply = QMessageBox::question(
                    this, "Edit Zoo Area",
                    "Are you sure you want to edit this area?",
                    QMessageBox::Yes | QMessageBox::No);

                if (reply == QMessageBox::Yes) {
                    zoo->getSpace(currentAreaIndex)->setCapacity(area_capacity);
                    QMessageBox::information(this, "Edit Zoo Area", "Edit Successful");
                }
            }
        }
    }
    else {
        QMessageBox::warning(this, "Edit Zoo Area", "There are no Zoo Area to edit.");
    }
    ui->IntegerValue->setText("");
}

void SpaceModify::on_GoBack_clicked()
{
    emit goBack();
}

void SpaceModify::on_TypeComboBox_currentIndexChanged(const QString& text)
{
    std::string area_name = text.toStdString();
    setAreaImage(area_name);
    currentAreaImage = area_name;
    ui->IntegerValue->setText("");
}

void SpaceModify::settingValues(Monkey::Zoo* zoo)
{
    ui->TypeComboBox->addItem("Hospital");
    ui->TypeComboBox->addItem("Enclosure");
    ui->TypeComboBox->addItem("Cage");
}

void SpaceModify::setAreaImage(const std::string& icon_name) {
    QString iconNameQString = QString::fromStdString(icon_name);
    QString filePath = QString("MonkeyZooManager/qt/images/") + iconNameQString;
    QPixmap pixmap(filePath);

    ui->Icon->setPixmap(pixmap);
    ui->Icon->setScaledContents(true);
    ui->Icon->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->Icon->resize(pixmap.size());
    ui->Icon->setAlignment(Qt::AlignCenter);
}

void SpaceModify::custom_init()
{
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    if (zoo->getSpaceCount() != 0) {
        std::string area_name = getSpaceName(zoo->getSpace(currentAreaIndex));
        ui->TypeComboBox->setCurrentText(QString::fromStdString(area_name));
        ui->IntegerValue->setText(QString::number(zoo->getSpace(currentAreaIndex)->getCapacity()));
    }
    else {
        ui->TypeComboBox->setCurrentText("Cage");
        ui->IntegerValue->setText("");
    }
}