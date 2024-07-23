#include "area_modify.h"
#include "ui_area_modify.h"

AreaModify::AreaModify(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::AreaModify)
{
    ui->setupUi(this);
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