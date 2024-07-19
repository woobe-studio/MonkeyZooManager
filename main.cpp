#include <QApplication>
#include "login.h"
#include "../src/monkey.hpp"

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

void custom_init() {
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::User* usr = new Monkey::User;
    usr->setUsername("boss");
    usr->setPassword("strong");
    Monkey::Zoo* zoo = new Monkey::Zoo;
    zoo->setZooName("Local Zoo");
    usr->setZoo(zoo);
    Monkey::Cage* testspace = new Monkey::Cage;
    zoo->addSpace(testspace);
    testspace->setCapacity(10);
    Monkey::Cage* testspace2 = new Monkey::Cage;
    zoo->addSpace(testspace2);
    testspace2->setCapacity(10);
    Monkey::Enclosure* testspace3 = new Monkey::Enclosure;
    zoo->addSpace(testspace3);
    testspace3->setCapacity(20);
    Monkey::Hospital* testspace4 = new Monkey::Hospital;
    zoo->addSpace(testspace4);
    testspace4->setCapacity(5);
    authorizationDaemon->addUser(usr);
    int i = 0;
    while (i < 2) {
        Monkey::HeisenMonkey* itAnimal = new Monkey::HeisenMonkey;
        int j = 0;
        itAnimal->setName("medd" + i);
        itAnimal->setAge(i);
        while (j < 2) {
            Monkey::Note* itNote = new Monkey::Note;
            itAnimal->addNote(itNote);
            j++;
        }
        testspace2->addAnimal(itAnimal);
        i++;
    }
    i = 0;
    while (i < 2) {
        Monkey::DartMonkey* itAnimal = new Monkey::DartMonkey;
        itAnimal->setName("mnk" + i);
        itAnimal->setAge(i);
        int j = 0;
        while (j < 2) {
            Monkey::Note* itNote = new Monkey::Note;
            itAnimal->addNote(itNote);
            j++;
        }
        testspace->addAnimal(itAnimal);
        i++;
    }
}