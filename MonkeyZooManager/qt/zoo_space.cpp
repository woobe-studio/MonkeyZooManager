#include "zoo_space.h"
#include "ui_zoo_space.h"
#include <QPixmap>
#include <QLabel>

ZooSpace::ZooSpace(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::ZooSpace)
{
    ui->setupUi(this);
    setMinimumSize(360, 640);
    resize(360, 640);

    currentIndex = 0;

    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    QString new_zoo_name = QString::fromStdString(zoo->getZooName());
    ui->EnterTitle->setText(new_zoo_name);
    if (zoo->getSpaceCount() != 0)
        settingValues(zoo->getSpace(currentIndex));


}

ZooSpace::~ZooSpace()
{
    delete ui;
}

void ZooSpace::on_Previous_clicked()
{
    move_through_spaces(true);
}

void ZooSpace::on_Next_clicked()
{
    move_through_spaces(false);
}

void ZooSpace::on_GoTo_clicked()
{
    // Handle Go to button click
}

void ZooSpace::on_GoBack_clicked()
{
    emit goBack();
    // Handle Go Back button click
}

void ZooSpace::move_through_spaces(bool reverse)
{
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    if (zoo->getSpaceCount() != 0)
    {
        if (reverse) {
            if (currentIndex > 0) {
                currentIndex -= 1;
                settingValues(zoo->getSpace(currentIndex));
            }
        }
        else
        {
            if (currentIndex + 1 != zoo->getSpaceCount()) {
                currentIndex += 1;
                settingValues(zoo->getSpace(currentIndex));
            }
        }
    }
}

void ZooSpace::settingValues(Monkey::Space* space)
{
    std::string space_name;
    if (Monkey::Enclosure* enclosurePtr = dynamic_cast<Monkey::Enclosure*>(space)) {
        space_name = "Enclosure";
    }
    else if (Monkey::Hospital* hospitalPtr = dynamic_cast<Monkey::Hospital*>(space)) {
        space_name = "Hospital";
    }
    else if (Monkey::Cage* cagePtr = dynamic_cast<Monkey::Cage*>(space)) {
        space_name = "Cage";
    }
    setAreaImage(space_name);
    ui->Name->setText(QString::fromStdString(space_name));
    ui->Space->setText("Monkeys: " + QString::number(space->getCount()));
}

void ZooSpace::setAreaImage(const std::string& icon_name) {
    QString iconNameQString = QString::fromStdString(icon_name);
    QString filePath = QString("MonkeyZooManager/qt/") + iconNameQString;
    QPixmap pixmap(filePath);

    ui->Icon->setPixmap(pixmap);
    ui->Icon->setScaledContents(true);
    ui->Icon->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->Icon->resize(pixmap.size());
    ui->Icon->setAlignment(Qt::AlignCenter);
}