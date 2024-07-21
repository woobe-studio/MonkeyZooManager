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

signals:
    void goBack();

private slots:
    void on_Previous_clicked();
    void on_Next_clicked();
    void on_GoTo_clicked();
    void on_GoBack_clicked();

private:
    Ui::ZooSpace* ui;
    int currentIndex;
    void move_through_spaces(bool reverse);
    void settingValues(Monkey::Space* space);
    void setAreaImage(const std::string& icon_name);
};

#endif // ZOO_SPACE_H