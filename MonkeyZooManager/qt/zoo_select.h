#ifndef ZOOSELECT_H
#define ZOOSELECT_H

#include <QMainWindow>
#include "ui_zoo_select.h"

#include "../src/monkey.hpp"

namespace Ui {
    class ZooSelect;
}

class ZooSelect : public QMainWindow
{
    Q_OBJECT

public:
    explicit ZooSelect(QWidget* parent = nullptr);
    ~ZooSelect();

signals:
    void goBack();
    void goSpace();

private slots:
    void on_GoTo_clicked();
    void on_GoBack_clicked();

private:
    Ui::ZooSelect* ui;
    void settingValues(Monkey::Zoo* zoo);
};

#endif // ZOOSELECT_H