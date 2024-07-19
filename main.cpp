#include <QApplication>
#include "login.h"
#include "scripts.h"  // Include the header file for custom_init

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    LoginForm w;
    custom_init();  // Call custom_init from scripts.cpp
    QObject::connect(&w, &LoginForm::loginSuccessful, [&]() {
        // This lambda function will be executed when loginSuccessful is emitted
        });

    w.show();
    return a.exec();
}
