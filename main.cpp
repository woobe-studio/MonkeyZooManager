#include <QApplication>
#include "qt/templates/login/login.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    LoginForm w;
    w.show();
    return a.exec();
}
