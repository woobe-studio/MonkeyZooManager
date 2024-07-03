#ifndef MONKE_H
#define MONKE_H
#ifdef __linux__
#include <bits/types/struct_tm.h>
#endif
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <string>
#include <streambuf>
#include <iostream>
#include <cstdio>
#include <functional>
#include <cstring>
#include "../libs/bcrypt.h"

namespace Monke
{
    class Space;
    class Animal;
    enum class Rarity;
    enum class userType;
    class Monkey;
    class Note;
    class MedicalNote;
    class BehavioralNote;
    class OtherNote;
    class ProboscisMonkey;
    class GuineaBaboon;
    class NightMonkey;
    class Lemur;
    class Zoo;
    class Enclosure;
    class Cage;
    class Hospital;
    class User;
    class AuthDaemon;
    class LoggingDaemon;
    class TimeDaemon;

    class Zoo
    {
    private:
        std::string name;
        std::vector<Space *> spaces;

    public:
        Zoo();
        ~Zoo();
        int setZooName(std::string newName);
        std::string getZooName();
        int addSpace(Space *spaceToAdd);
        int removeSpace(Space *spaceToRemove);
    };

    class Space
    {
    protected:
        std::vector<Animal *> animals;
        int capacity;

    public:
        Space();
        virtual ~Space();

        virtual int getCapacity();
        virtual int getCount();
        virtual Animal *getAnimal(int countInVector);

        virtual int setCapacity(int newCapacity);

        virtual int addAnimal(Animal *animal);
        virtual int removeAnimal(Animal *animal);

        virtual bool isFull();
        virtual bool isEmpty();
    };

    class Cage : public Space
    {
    };

    class Hospital : public Space
    {
    };

    struct hourMin
    {
        int hour;
        int minute;
    };

    class Enclosure : public Space
    {
    private:
        hourMin openTime;
        hourMin closeTime;
        int visitorSpots;
        float temperature;

    public:
        Enclosure();

        ~Enclosure();

        hourMin getOpenTime();
        hourMin getCloseTime();
        int getVisitorSpots();
        float getTemperature();

        void setOpenTime(hourMin newOpenTime);
        void setCloseTime(hourMin newCloseTime);
        void setVisitorSpots(int newVisitorSpots);
        void setTemperature(float newTemperature);
    };

    enum class Rarity
    {
        COMMON,
        UNCOMMON,
        RARE,
        EPIC,
        LEGENDARY
    };

    class Animal
    {
    protected:
        Space *space;
        std::string name;
        int age;
        Rarity rarity;
        std::vector<Note *> notes;

    public:
        Animal();
        virtual ~Animal();

        virtual std::string getName();
        virtual Space *getSpace();
        virtual int getAge();
        virtual Rarity getRarity();

        virtual void setSpace(Space *newSpace);
        virtual void setName(const std::string &animalName);
        virtual void setAge(int animalAge);
        virtual void setRarity(Rarity animalRarity);

        virtual void addNote(Note *newNote);
        virtual int removeNote(Note *noteToRemove);
    };

    class Monkey : public Animal
    {
    protected:
        std::string monkeOrigin;
        float monkeJumpHeight;
        float toleratedTempMax;
        float toleratedTempMin;
        float foodPounds;

    public:
        Monkey();
        ~Monkey();

        std::string getMonkeOrigin();
        float getMonkeJumpHeight();
        float getToleratedTempMax();
        float getToleratedTempMin();
        float getFoodPounds();

        void setMonkeOrigin(std::string newMonkeOrigin);
        void setMonkeJumpHeight(float newMonkeJumpHeight);
        void setToleratedTempMax(float newTemp);
        void setToleratedTempMin(float newTemp);
        void setFoodPounds(float newFoodPounds);
    };

    class Note
    {
    private:
        Animal *animal;
        tm *date;
        std::string text;

    public:
        Note();
        virtual ~Note();
        virtual Animal *getAnimal();
        virtual tm *getDate();
        virtual std::string getNote();

        virtual int setNote(const std::string &note);
        virtual int setAnimal(Animal *connectedAnimal);
        virtual int setTime(tm *ltm);
        virtual int setTimeNow();
    };

    class MedicalNote : public Note
    {
    };

    class BehavioralNote : public Note
    {
    };

    class OtherNote : public Note
    {
    };

    class ProboscisMonkey : public Monkey
    {
    };

    class GuineaBaboon : public Monkey
    {
    };

    class NightMonkey : public Monkey
    {
    };

    class Lemur : public Monkey
    {
    };

    enum class userType
    {
        STANDARD,
        ADMIN
    };

    class User
    {
    private:
        std::string username;
        std::string hashOfPassword;
        userType accType;
        Zoo *accessToZoo;

    public:
        User();
        User(std::string username, std::string password, userType accType, Zoo *zoo);
        ~User();

        std::string getUsername();
        userType getAccType();
        Zoo *getZoo();
        bool checkPassword(const std::string &password);

        void setUsername(const std::string &username);
        void setPassword(const std::string &password);
        void setPassword(const std::string &password, int bcryptIterations);
        int setAccType(int newType);
        void setZoo(Zoo *newZoo);
    };

    class AuthDaemon
    {
    private:
        static AuthDaemon *instance;
        std::vector<User *> users;
        User *loggedInUser;

    private:
        AuthDaemon();
        //~AuthDaemon();

    public:
        ~AuthDaemon();
        static AuthDaemon *getInstance();
        static void destroyDaemon();

        int login(const std::string &username, const std::string &password);
        void logout();

        bool isLoggedIn(User *user);
        bool isLoggedInUserAdmin();

        bool doesUsernameExist(std::string username);
        int addUser(User *user);
        int remUser(User *user);
        int remUser(std::string user);

        User *retPointerOfUsername(std::string username);
    };

    class LoggingDaemon
    {
    private:
        static LoggingDaemon *instance;
        bool enabledAction;
        bool enabledAuth;
        bool enabledAdminActions;
        LoggingDaemon();
        std::string timeStringNow();

    public:
        ~LoggingDaemon();
        static LoggingDaemon *getInstance();
        static void destroyDaemon();
        void logAction(const std::string &action);
        void logAuth(User *user, const std::string &action);
        void logAdminAction(User *user, const std::string &action);
        void logInternal(const std::string &error);

        bool getEnabledAction();
        bool getEnabledAuth();
        bool getEnabledAdminAction();

        void setEnabledAction(bool value);
        void setEnabledAuth(bool value);
        void setEnabledAdminAction(bool value);
    };

    class TimeDaemon
    {
    public:
        static tm *getNewTimePointerNow();
        static tm *copyTimefromTimePointer(tm *toCopy);
    };
}

#endif
