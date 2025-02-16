#ifndef ZOO_SPACE_H
#define ZOO_SPACE_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsView>

#include "../src/monkey.hpp"

namespace Ui {
    class ZooSpace;
}

class ZooSpace : public QMainWindow
{
    Q_OBJECT

public:
    explicit ZooSpace(QWidget* parent = nullptr);
    ~ZooSpace();
    int currentAreaIndex;
    int currentMonkeyIndex;
    void custom_init();

signals:
    void goBack();
    void goEdit();

private slots:
    void on_Previous_clicked();
    void on_Next_clicked();
    void on_GoBack_clicked();
    void on_Edit_clicked();

private:
    Ui::ZooSpace* ui;
    void move_through_spaces(bool reverse);
    void settingValues(Monkey::Space* space);
    void setAreaImage(const std::string& icon_name);
};

#endif // ZOO_SPACE_H
