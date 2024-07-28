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
    if (zoo->getSpace(currentAreaIndex)->getCount() != 0) {
        QMessageBox::StandardButton reply = QMessageBox::question(
            this, "Delete Zoo Area",
            "Are you sure you want to delete this monkey?",
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            zoo->getSpace(currentAreaIndex)->removeAnimal(zoo->getSpace(currentAreaIndex)->getAnimal(currentMonkeyIndex));
            QMessageBox::information(this, "Delete Monkey", "Delete Successful");
        }
    }
    else {
        QMessageBox::warning(this, "Delete Monkey", "There are no monkeys to delete.");
    }
    ui->Age->setText("");
    // Handle delete button click
}


void SpaceModify::on_CreateButton_clicked() {
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    QString age_capacity_text = ui->Age->text();
    if (age_capacity_text.isEmpty()) {
        QMessageBox::warning(this, "Create New Monkey", "Please set age of the monkey.");
    }
    else {
        int age = age_capacity_text.toInt();
        if (age < 0) {
            QMessageBox::warning(this, "Create New Monkey", "New age is set incorrectly. Please fix it.");
        }
        else {
            QMessageBox::StandardButton reply = QMessageBox::question(
                this, "Create New Monkey",
                "Are you sure you want to create this monkey?",
                QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                std::string monkey_name = ui->TypeComboBox->currentText().toStdString();
                std::string rarity = ui->RarityTypeComboBox->currentText().toStdString();
                if (monkey_name == "Rich Monkey") {
                    Monkey::RichMonkey* new_monkey = new Monkey::RichMonkey;
                    zoo->getSpace(currentAreaIndex)->addAnimal(new_monkey);
                    new_monkey->setAge(age);
                    new_monkey->setRarity(StringToRarity(rarity));
                }
                else if (monkey_name == "Student Monkey") {
                    Monkey::StudentMonkey* new_monkey = new Monkey::StudentMonkey;
                    zoo->getSpace(currentAreaIndex)->addAnimal(new_monkey);
                    new_monkey->setAge(age);
                    new_monkey->setRarity(StringToRarity(rarity));
                }
                else if (monkey_name == "Lava Monkey") {
                    Monkey::LavaMonkey* new_monkey = new Monkey::LavaMonkey;
                    zoo->getSpace(currentAreaIndex)->addAnimal(new_monkey);
                    new_monkey->setAge(age);
                    new_monkey->setRarity(StringToRarity(rarity));
                }
                else if (monkey_name == "Dart Monkey") {
                    Monkey::DartMonkey* new_monkey = new Monkey::DartMonkey;
                    zoo->getSpace(currentAreaIndex)->addAnimal(new_monkey);
                    new_monkey->setAge(age);
                    new_monkey->setRarity(StringToRarity(rarity));
                }
                else if (monkey_name == "Galactic Monkey") {
                    Monkey::GalacticMonkey* new_monkey = new Monkey::GalacticMonkey;
                    zoo->getSpace(currentAreaIndex)->addAnimal(new_monkey);
                    new_monkey->setAge(age);
                    new_monkey->setRarity(StringToRarity(rarity));
                }
                QMessageBox::information(this, "Create New Monkey", "Create Successful");
            }
        }
    }
    ui->Age->setText("");
}

void SpaceModify::on_EditButton_clicked()
{
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    if (zoo->getSpace(currentAreaIndex)->getCount() != 0) {
        QString age_text = ui->Age->text();
        if (age_text.isEmpty()) {
            QMessageBox::warning(this, "Edit Monkey", "Please set age of the monkey.");
        }
        else {
            int age = age_text.toInt();
            if (age < zoo->getSpace(currentAreaIndex)->getAnimal(currentMonkeyIndex)->getAge()) {
                QMessageBox::warning(this, "Edit Monkey", "New age is smaller than a current one.");
            }
            else {
                QMessageBox::StandardButton reply = QMessageBox::question(
                    this, "Edit Monkey",
                    "Are you sure you want to edit this monkey?",
                    QMessageBox::Yes | QMessageBox::No);

                if (reply == QMessageBox::Yes) {
                    zoo->getSpace(currentAreaIndex)->getAnimal(currentMonkeyIndex)->setAge(age);
                    std::string rarity = ui->RarityTypeComboBox->currentText().toStdString();
                    zoo->getSpace(currentAreaIndex)->getAnimal(currentMonkeyIndex)->setRarity(StringToRarity(rarity));
                    QMessageBox::information(this, "Edit Monkey", "Edit Successful");
                }
            }
        }
    }
    else {
        QMessageBox::warning(this, "Edit Monkey", "There are no monkeys to edit.");
    }
    ui->Age->setText("");
}

void SpaceModify::on_GoBack_clicked()
{
    emit goBack();
}

void SpaceModify::on_TypeComboBox_currentIndexChanged(const QString& text)
{
    std::string monkey_name = text.toStdString();
    setAreaImage(monkey_name);
    currentAreaImage = monkey_name;
    ui->Age->setText("");
}

void SpaceModify::settingValues(Monkey::Zoo* zoo)
{
    ui->TypeComboBox->addItem("Dart Monkey");
    ui->TypeComboBox->addItem("Galactic Monkey");
    ui->TypeComboBox->addItem("Lava Monkey");
    ui->TypeComboBox->addItem("Rich Monkey");
    ui->TypeComboBox->addItem("Student Monkey");

    ui->RarityTypeComboBox->addItem("COMMON");
    ui->RarityTypeComboBox->addItem("UNIQUE");
    ui->RarityTypeComboBox->addItem("RARE");
    ui->RarityTypeComboBox->addItem("EPIC");
    ui->RarityTypeComboBox->addItem("MAGIC");
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
    if (zoo->getSpace(currentAreaIndex)->getCount() != 0) {
        Monkey::Animal* monkey = zoo->getSpace(currentAreaIndex)->getAnimal(currentMonkeyIndex);
        std::string monkey_name = getMonkeyName(monkey);
        ui->TypeComboBox->setCurrentText(QString::fromStdString(monkey_name));
        ui->RarityTypeComboBox->setCurrentText(QString::fromStdString(rarityToString(monkey->getRarity())));
        ui->Age->setText(QString::number(monkey->getAge()));
    }
    else {
        ui->TypeComboBox->setCurrentText("Rich Monkey");
        ui->RarityTypeComboBox->setCurrentText("COMMON");
        ui->Age->setText("");
    }
}