#include <QApplication>
#include "scripts.h"  // Include the header file for custom_init
#include "login.h"
#include "zoo_areas.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    custom_init();

    LoginForm loginForm;
    ZooAreas* zooAreas = nullptr;
    loginForm.show();

    QObject::connect(&loginForm, &LoginForm::loginSuccessful, [&]() {
        loginForm.close();

        if (!zooAreas) {
            zooAreas = new ZooAreas;
            QObject::connect(zooAreas, &ZooAreas::goBack, [&]() {
                zooAreas->close();
                loginForm.show();
                });
        }

        zooAreas->show();
        });


    return app.exec();
}
