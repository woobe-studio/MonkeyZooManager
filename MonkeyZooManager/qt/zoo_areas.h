#ifndef ZOO_AREAS_H
#define ZOO_AREAS_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsView>

#include "../src/monkey.hpp"

namespace Ui {
    class ZooAreas;
}

class ZooAreas : public QMainWindow
{
    Q_OBJECT

public:
    explicit ZooAreas(QWidget* parent = nullptr);
    ~ZooAreas();
    int currentAreaIndex;

signals:
    void goBack();
    void goSpace();
    void modifyArea();

private slots:
    void on_Previous_clicked();
    void on_Next_clicked();
    void on_Modify_clicked();
    void on_GoTo_clicked();
    void on_GoBack_clicked();

private:
    Ui::ZooAreas* ui;
    void move_through_spaces(bool reverse);
    void settingValues(Monkey::Space* space);
    void setAreaImage(const std::string& icon_name);
};

#endif // ZOO_AREAS_H
