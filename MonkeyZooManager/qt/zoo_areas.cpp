#include "zoo_areas.h"
#include "ui_zoo_areas.h"

ZooAreas::ZooAreas(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::ZooAreas)
{
    ui->setupUi(this);

    // Connect signals and slots
    connect(ui->Previous, &QPushButton::clicked, this, &ZooAreas::on_Previous_clicked);
    connect(ui->Next, &QPushButton::clicked, this, &ZooAreas::on_Next_clicked);
    connect(ui->GoTo, &QPushButton::clicked, this, &ZooAreas::on_GoTo_clicked);
    connect(ui->GoBack, &QPushButton::clicked, this, &ZooAreas::on_GoBack_clicked);
}

ZooAreas::~ZooAreas()
{
    delete ui;
}

void ZooAreas::on_Previous_clicked()
{
    // Handle Previous button click
}

void ZooAreas::on_Next_clicked()
{
    // Handle Next button click
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
