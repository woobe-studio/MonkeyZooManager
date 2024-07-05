#include "MonkeyZooManager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MonkeyZooManager w;
    w.show();
    return a.exec();
}
