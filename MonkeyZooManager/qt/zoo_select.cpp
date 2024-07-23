#include "zoo_select.h"
#include <QMessageBox>

ZooSelect::ZooSelect(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ZooSelect)
{
    ui->setupUi(this);
}

ZooSelect::~ZooSelect()
{
    delete ui;
}

void ZooSelect::on_GoTo_clicked()
{
    // Add your go to zoo button handling code here
    QMessageBox::information(this, "Go To Zoo", "Go to Zoo button clicked!");
}

void ZooSelect::on_GoBack_clicked()
{
    // Add your go back button handling code here
    QMessageBox::information(this, "Go Back", "Go Back button clicked!");
}
