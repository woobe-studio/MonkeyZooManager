#include <QApplication>
#include "scripts.h"  // Include the header file for custom_init
#include "login.h"
#include "zoo_areas.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    LoginForm loginForm;
    ZooAreas* zooAreas = nullptr;

    custom_init();

    QObject::connect(&loginForm, &LoginForm::loginSuccessful, [&]() {
        loginForm.hide();

        if (!zooAreas) {
            zooAreas = new ZooAreas;
        }

        zooAreas->show();
        });

    loginForm.show();

    return app.exec();
}
