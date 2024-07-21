#include "zoo_space.h"
#include "ui_zoo_space.h"

#include "scripts.h"

ZooSpace::ZooSpace(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::ZooSpace)
{
    ui->setupUi(this);
    setMinimumSize(360, 640);
    resize(360, 640);

    currentMonkeyIndex = 0;

    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::Zoo* zoo = authorizationDaemon->retPointerOfLoggedInUser()->getZoo();
    QString new_space_name = QString::fromStdString(getSpaceName(zoo->getSpace(currentAreaIndex)));
    ui->EnterTitle->setText(new_space_name);
    if (zoo->getSpace(currentAreaIndex)->getCapacity() != 0)
        settingValues(zoo->getSpace(currentAreaIndex));


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
    qWarning() << zoo->getSpace(currentAreaIndex)->getCount();
    if (zoo->getSpace(currentAreaIndex)->getCount() != 0)
    {
        if (reverse) {
            if (currentMonkeyIndex > 0) {
                currentMonkeyIndex -= 1;
                settingValues(zoo->getSpace(currentAreaIndex));
            }
        }
        else
        {
            if (currentMonkeyIndex + 1 != zoo->getSpace(currentAreaIndex)->getCount()) {
                currentMonkeyIndex += 1;
                settingValues(zoo->getSpace(currentAreaIndex));
            }
        }
    }
}

void ZooSpace::settingValues(Monkey::Space* space)
{
    Monkey::Animal* monkey = space->getAnimal(currentMonkeyIndex);
    std::string monkey_name = getMonkeyName(monkey);
    setAreaImage(monkey_name);
    ui->Name->setText(QString::fromStdString(monkey_name));
    Monkey::Rarity rarity = monkey->getRarity();
    ui->Space->setText(QString::fromStdString(rarityToString(rarity)));
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

void ZooSpace::resetValues()
{
    ui->Name->setText("");
    ui->Space->setText("");
    ui->EnterTitle->setText("");
    currentMonkeyIndex = 0;
}