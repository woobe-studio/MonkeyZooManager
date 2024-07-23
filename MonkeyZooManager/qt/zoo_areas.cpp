#include "zoo_areas.h"
#include "ui_zoo_areas.h"

#include "scripts.h"

ZooAreas::ZooAreas(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::ZooAreas)
{
    ui->setupUi(this);
    setMinimumSize(360, 640);
    resize(360, 640);

    currentAreaIndex = 0;
    
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    QString new_zoo_name = QString::fromStdString(zoo->getZooName());
    ui->EnterTitle->setText(new_zoo_name);
    if (zoo->getSpaceCount() != 0)
        settingValues(zoo->getSpace(currentAreaIndex));


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

void ZooAreas::on_Modify_clicked()
{
    emit modifyArea();
}


void ZooAreas::on_GoTo_clicked()
{
    emit goSpace();
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
            if (currentAreaIndex > 0) {
                currentAreaIndex -= 1;
                settingValues(zoo->getSpace(currentAreaIndex));
            }
        }
        else
        {
            if (currentAreaIndex + 1 != zoo->getSpaceCount()) {
                currentAreaIndex += 1;
                settingValues(zoo->getSpace(currentAreaIndex));
            }
        }
    }
}

void ZooAreas::settingValues(Monkey::Space* space)
{
    std::string space_name = getSpaceName(space);
    setAreaImage(space_name);
    ui->Name->setText(QString::fromStdString(space_name));
    ui->Space->setText("Monkeys: " + QString::number(space->getCount()));
}

void ZooAreas::setAreaImage(const std::string& icon_name) {
    QString iconNameQString = QString::fromStdString(icon_name);
    QString filePath = QString("MonkeyZooManager/qt/") + iconNameQString;
    QPixmap pixmap(filePath);

    ui->Icon->setPixmap(pixmap);
    ui->Icon->setScaledContents(true);
    ui->Icon->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->Icon->resize(pixmap.size());
    ui->Icon->setAlignment(Qt::AlignCenter);
}