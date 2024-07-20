#include "zoo_areas.h"
#include "ui_zoo_areas.h"
#include "../src/monkey.hpp"

ZooAreas::ZooAreas(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::ZooAreas)
{
    ui->setupUi(this);

    // Connect signals and slots
    connect(ui->Previous, &QPushButton::clicked, this, &ZooAreas::on_Previous_clicked);
    connect(ui->Next, &QPushButton::clicked, this, &ZooAreas::on_Next_clicked);
    connect(ui->GoTo, &QPushButton::clicked, this, &ZooAreas::on_GoTo_clicked);
    connect(ui->GoBack, &QPushButton::clicked, this, &ZooAreas::on_GoBack_clicked);

    currentIndex = 0;
    str zoo_name = ui->EnterTitle->text().toStdString();
    ui->EnterTitle->setText(zoo_name);
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
        if (reverse)
            if (currentIndex != 0)
                currentIndex -= 1;
        else
        {
            if (currentIndex + 1 != zoo->getSpaceCount())
                currentIndex += 1;
        }
    }
}