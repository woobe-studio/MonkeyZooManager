#ifndef ZOOSELECT_H
#define ZOOSELECT_H

#include <QMainWindow>
#include "ui_zoo_select.h"

namespace Ui {
    class ZooSelect;
}

class ZooSelect : public QMainWindow
{
    Q_OBJECT

public:
    explicit ZooSelect(QWidget* parent = nullptr);
    ~ZooSelect();

private slots:
    void on_GoTo_clicked();
    void on_GoBack_clicked();

private:
    Ui::ZooSelect* ui;
};

#endif // ZOOSELECT_H