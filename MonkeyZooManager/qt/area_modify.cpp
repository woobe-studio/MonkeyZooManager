#include "area_modify.h"
#include "ui_area_modify.h"

AreaModify::AreaModify(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::AreaModify)
{
    ui->setupUi(this);
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
