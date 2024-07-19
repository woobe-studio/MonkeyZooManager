#include <QApplication>
#include "login.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    LoginForm w;

    QObject::connect(&w, &LoginForm::loginSuccessful, [&]() {
        // This lambda function will be executed when loginSuccessful is emitted
        });

    w.show();
    return a.exec();
}
