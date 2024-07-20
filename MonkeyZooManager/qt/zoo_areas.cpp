#include "zoo_areas.h"
#include "ui_zoo_areas.h"
#include "../src/monkey.hpp"

ZooAreas::ZooAreas(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::ZooAreas)
{
    ui->setupUi(this);

    currentIndex = 0;
    
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    QString new_zoo_name = QString::fromStdString(zoo->getZooName());
    ui->EnterTitle->setText(new_zoo_name);
}

ZooAreas::~ZooAreas()
{
    delete ui;
}

void ZooAreas::on_Previous_clicked()
{
    move_through_spaces(true);
}

void ZooAreas::on_Next_clicked()
{
    move_through_spaces(false);
}

void ZooAreas::on_GoTo_clicked()
{
    // Handle Go to button click
}

void ZooAreas::on_GoBack_clicked()
{
    emit goBack();
    // Handle Go Back button click
}

void ZooAreas::move_through_spaces(bool reverse)
{
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    if (zoo->getSpaceCount() != 0)
    {
        if (reverse) {
            if (currentIndex > 0) {
                currentIndex -= 1;
                qDebug() << "The number is:" << currentIndex;
            }
        }
        else
        {
            if (currentIndex + 1 != zoo->getSpaceCount()) {
                currentIndex += 1;
                qDebug() << "The number is:" << currentIndex;
            }
        }
    }
}