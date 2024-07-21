#ifndef MONKEY_H
#define MONKEY_H
#include <fstream>
#ifdef __linux__
#include <bits/types/struct_tm.h>
#endif
#include <time.h>
#include <stdexcept>
#include <ctime>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <string>
#include <streambuf>
#include <iostream>
#include <cstdio>
#include <functional>
#include <cstring>
#include <ios>
#include "../libs/bcrypt.h"
#include "../libs/json.hpp"

namespace Monkey
{
    class SerializationDaemon;
    class Space;
    class Animal;
    enum class Rarity;
    enum class userType;
    class Monkey;
    class Note;
    class MedicalNote;
    class BehavioralNote;
    class OtherNote;
    class HeisenMonkey;
    class StudentMonkey;
    class GalacticMonkey;
    class DartMonkey;
    class LavaMonkey;
    class Zoo;
    class Enclosure;
    class Cage;
    class Hospital;
    class User;
    class AuthDaemon;
    class LoggingDaemon;
    class TimeDaemon;

    using json = nlohmann::json;

    class SerializationDaemon
    {
    private:
        static SerializationDaemon *instance;
        std::vector<Zoo *> zoos;
        SerializationDaemon();

    public:
        ~SerializationDaemon();
        static SerializationDaemon *getInstance();
        static void destroyDaemon();

        int size();
        Zoo *zooByIndex(long unsigned int countInVector);
        Zoo *zooByName(const std::string &uuidStr);

        void addZoo(Zoo *newZoo);
        void removeZoo(Zoo *toDelZoo);

        void save();
        void load();
    };

    class Zoo
    {
    private:
        std::string name;
        std::vector<Space *> spaces;

    public:
        int currentSpace;
        Zoo();
        ~Zoo();
        void setZooName(std::string newName);
        std::string getZooName();
        Space *getSpace(long unsigned int countInVector);
        int getSpaceCount();
        void addSpace(Space *spaceToAdd);
        void removeSpace(Space *spaceToRemove);
        void to_json(json &j) const;
        void from_json(const json &j);
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
        virtual Animal *getAnimal(long unsigned int countInVector);

        virtual bool setCapacity(int newCapacity);

        virtual void addAnimal(Animal *animal);
        virtual void removeAnimal(Animal *animal);

        virtual bool isFull();
        virtual bool isEmpty();

        virtual void to_json(json &j) const;
        virtual void from_json(const json &j);
    };

    class Cage : public Space
    {
    private:
        int cageId;
        std::string cageName;
        int numberOfCameras;
        std::string cageColor;

    public:
        Cage();
        ~Cage();

        int getCageId();
        std::string getName();
        int getNumberOfCams();
        std::string getCageColor();

        void setCageId(int newCageId);
        void setName(std::string newName);
        void setNumberOfCams(int newNumberOfCams);
        void setCageColor(std::string newCageColor);

        void to_json(json &j) const override;
        void from_json(const json &j) override;
    };

    class Hospital : public Space
    {
    private:
        int medicineQuantity;
        int bedsCount;
        int volunteerAmount;

    public:
        Hospital();

        ~Hospital();

        int getMedicineQuantity();
        int getBedsCount();
        int getVolunteerAmount();

        void setMedicineQuantity(int newMedicineQuantity);
        void setBedsCount(int newBedCount);
        void setVolunteerAmount(int newVolunteerAmount);

        void to_json(json &j) const override;
        void from_json(const json &j) override;
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

        void to_json(json &j) const override;
        void from_json(const json &j) override;
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
        virtual void removeNote(Note *noteToRemove);

        virtual void to_json(json &j) const;
        virtual void from_json(const json &j);
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
        virtual ~Monkey();

        virtual std::string getMonkeOrigin();
        virtual float getMonkeJumpHeight();
        virtual float getToleratedTempMax();
        virtual float getToleratedTempMin();
        virtual float getFoodPounds();

        virtual void setMonkeOrigin(std::string newMonkeOrigin);
        virtual void setMonkeJumpHeight(float newMonkeJumpHeight);
        virtual void setToleratedTempMax(float newTemp);
        virtual void setToleratedTempMin(float newTemp);
        virtual void setFoodPounds(float newFoodPounds);

        virtual void to_json(json &j) const override;
        virtual void from_json(const json &j) override;
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

        virtual void to_json(json &j) const;
        virtual void from_json(const json &j);
    };

    class MedicalNote : public Note
    {
    private:
        float costOfMedications;
        float proceduresCost;

    public:
        MedicalNote();

        ~MedicalNote();

        float getCostOfMedications();
        float getProceduresCost();

        void setCostOfMedications(float newCost);
        void setProceduresCost(float newCost);

        void to_json(json &j) const override;
        void from_json(const json &j) override;
    };

    class BehavioralNote : public Note
    {
    private:
        int mood;
        float sleepTime;
        float activeTime;
        bool isSocializing;

    public:
        BehavioralNote();

        ~BehavioralNote();

        int getMood();
        float getSleepTime();
        float getActiveTime();
        bool getIsSocializing();

        void setMood(int newMood);
        void setSleepTime(float newSleepTime);
        void setActiveTime(float newActiveTime);
        void setIsSocializing(bool newIsSocializing);

        void to_json(json &j) const override;
        void from_json(const json &j) override;
    };

    class OtherNote : public Note
    {
    private:
        std::string topic;

    public:
        OtherNote();

        ~OtherNote();

        std::string getTopic();

        void setTopic(const std::string &newTopic);

        void to_json(json &j) const override;
        void from_json(const json &j) override;
    };

    class HeisenMonkey : public Monkey
    {
    private:
        float poundsOfCandyCooked;

    public:
        HeisenMonkey();

        ~HeisenMonkey();

        float getPoundsOfCandyCooked();

        void setPoundsOfCandyCooked(float newPoundsOfCandyCooked);

        void to_json(json &j) const override;
        void from_json(const json &j) override;
    };

    class StudentMonkey : public Monkey
    {
    private:
        int examsToRetake;

    public:
        StudentMonkey();

        ~StudentMonkey();

        int getExamsToRetake();

        void setExamsToRetake(int newExamsToRetake);

        void to_json(json &j) const override;
        void from_json(const json &j) override;
    };

    class GalacticMonkey : public Monkey
    {
    private:
        int blackHolesCreated;

    public:
        GalacticMonkey();

        ~GalacticMonkey();

        int getBlackHolesCreated();

        void setBlackHolesCreated(int newBlackHolesCreated);

        void to_json(json &j) const override;
        void from_json(const json &j) override;
    };

    class DartMonkey : public Monkey
    {
    private:
        int baloonsPopped;

    public:
        DartMonkey();

        ~DartMonkey();

        int getBaloonsPopped();

        void setBaloonsPopped(int newbaloonsPopped);

        void to_json(json &j) const override;
        void from_json(const json &j) override;
    };

    class LavaMonkey : public Monkey
    {
    private:
        float jumpHeight;

    public:
        LavaMonkey();

        ~LavaMonkey();

        float getJumpHeight();

        void setJumpHeight(float newJump);

        void to_json(json &j) const override;
        void from_json(const json &j) override;
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
        User(const std::string &username, const std::string &password, userType accType, Zoo *zoo);
        ~User();

        std::string getUsername();
        userType getAccType();
        Zoo *getZoo();
        bool checkPassword(const std::string &password);

        void setUsername(const std::string &username);
        void setPassword(const std::string &password);
        void setPassword(const std::string &password, int bcryptIterations);
        void setAccType(userType newType);
        void setZoo(Zoo *newZoo);

        void to_json(json &j) const;
        void from_json(const json &j);
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

        bool login(const std::string &username, const std::string &password);
        void logout();

        bool isLoggedIn(User *user);
        bool isLoggedInUserAdmin();

        bool doesUsernameExist(std::string username);
        void addUser(User *user);
        void remUser(User *user);
        void remUser(std::string user);

        User *retPointerOfUsername(std::string username);
        User *retPointerOfLoggedInUser();

        void to_json(json &j) const;
        void from_json(const json &j);
    };

    class LoggingDaemon
    {
    private:
        static LoggingDaemon *instance;
        bool enabledAction;
        bool enabledAuth;
        bool enabledAdminActions;
        LoggingDaemon();
        std::fstream logFile;

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
        static std::string getCurrentTimeString();
        static std::string getTimeString(tm *toConvertToString);
    };
}

#endif
