#include "area_modify.h"
#include "ui_area_modify.h"

#include <QMessageBox>

AreaModify::AreaModify(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::AreaModify)
{
    ui->setupUi(this);

    setMinimumSize(360, 640);
    resize(360, 640);

    connect(ui->TypeComboBox, &QComboBox::currentTextChanged, this, &AreaModify::on_TypeComboBox_currentIndexChanged);
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    settingValues(zoo);
}

AreaModify::~AreaModify()
{
    delete ui;
}

void AreaModify::on_DeleteButton_clicked()
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
                // Code to delete the empty area
            }
        }
        else {
            QMessageBox::StandardButton reply = QMessageBox::question(
                this, "Delete Zoo Area",
                "Are you sure you want to delete this area?",
                QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                // Code to delete the area
            }
        }
    }
    else {
        QMessageBox::warning(this, "Delete Zoo Area", "There are no Zoo Areas to delete.");
    }
    ui->IntegerValue->setText("");
    // Handle delete button click
}


void AreaModify::on_GoTo_clicked()
{
    // Handle modify button click
}

void AreaModify::on_GoBack_clicked()
{
    emit goBack();
}

void AreaModify::on_TypeComboBox_currentIndexChanged(const QString& text)
{
    // Handle the event when a new item is selected from the combo box
    qDebug() << "Selected item:" << text;
}

void AreaModify::settingValues(Monkey::Zoo* zoo)
{
    ui->TypeComboBox->addItem("Hospital");
    ui->TypeComboBox->addItem("Enclosure");
    ui->TypeComboBox->addItem("Cage");
}