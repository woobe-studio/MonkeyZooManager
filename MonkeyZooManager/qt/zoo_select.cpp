#include "zoo_select.h"
#include <QMessageBox>

ZooSelect::ZooSelect(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ZooSelect)
{
    ui->setupUi(this);

    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    settingValues(zoo);
}

ZooSelect::~ZooSelect()
{
    delete ui;
}

void ZooSelect::on_GoTo_clicked()
{
    emit goArea();
}

void ZooSelect::on_GoBack_clicked()
{
    emit goBack();
}

void ZooSelect::settingValues(Monkey::Zoo* zoo)
{
    std::string zoo_name = zoo->getZooName();
    ui->Name->setText(QString::fromStdString(zoo_name));
}
