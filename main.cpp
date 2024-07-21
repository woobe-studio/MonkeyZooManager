#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "scripts.h"
#include "login.h"
#include "zoo_areas.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    custom_init();

    // Create and configure LoginForm
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
