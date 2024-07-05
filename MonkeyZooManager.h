#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MonkeyZooManager.h"

class MonkeyZooManager : public QMainWindow
{
    Q_OBJECT

public:
    MonkeyZooManager(QWidget *parent = nullptr);
    ~MonkeyZooManager();

private:
    Ui::MonkeyZooManagerClass ui;
};
