#ifndef MONKE_H
#define MONKE_H
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <string>
#include <streambuf>
#include <iostream>

class Space;
class Animal;
enum class Rarity;
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


class Zoo{
	private:
	std::string name;
	std::vector<Space*> spaces;
	public:
	Zoo();
	~Zoo();
	int setZooName(std::string newName);
	std::string getZooName();
	int addSpace(Space* spaceToAdd);
	int removeSpace(Space* spaceToRemove);
};

class Space{
	protected:
        std::vector<Animal*> animals;
	int capacity;
	int count;
        
	public:
        Space();
        virtual ~Space();
	virtual int addAnimal(Animal* animal);
	virtual int removeAnimal(Animal* animal);
	virtual int getCapacity();
	virtual int setCapacity(int newCapacity);
	virtual int getCount();
};

class Cage : public Space{};

class Hospital : public Space{};

class Enclosure : public Space{};


enum class Rarity {
    Common,
    Uncommon,
    Rare,
    Legendary,
    Epic
};

class Animal {
protected:
    Space* space;
    std::string name;
    int age;
    Rarity rarity;

public:
    void setSpace(Space* zoo);
    Space* getSpace();
    void setName(const std::string& animalName);
    std::string getName();
    void setAge(int animalAge);
    int getAge();
};

class Monkey : public Animal {
};

class Note {
private:
    Animal* animal;
    long date;
    std::string note;

public:
    Animal* getAnimal();
    long getDate();
    std::string getNote();
};

class MedicalNote : public Note {
};

class BehavioralNote : public Note {
};

class OtherNote : public Note {
};

class ProboscisMonkey : public Monkey {
};

class GuineaBaboon : public Monkey {
};

class NightMonkey : public Monkey {
};

class Lemur : public Monkey {
};


    class User {
    private:
        std::string username;
        std::string password;
        int accType;
        Zoo* accessToZoo;

    public:
        std::string getUsername();
        void setUsername(const std::string& username);
        std::string getPassword();
        void setPassword(const std::string& password);
        Zoo* getZoo();
        int setAccType(int newType);
        int getAccType();
        void setZoo(Zoo* newZoo);
    };

    class AuthDaemon {
    private:
        static AuthDaemon* instance;
        std::vector<User*> users;
        User* loggedInUser;

    private:
        AuthDaemon();
        //~AuthDaemon();
        
    public:
        ~AuthDaemon();
        static AuthDaemon* getInstance();
        static void destroyDaemon();
        int login(User* user);
        int login(const std::string& username, const std::string& password);
        void logout();
        bool isLoggedIn(User* user);
        bool isLoggedInUserAdmin();
        void addUser(User* user);
        void remUser(User* user);
    };

    class LoggingDaemon {
    private:
        static LoggingDaemon* instance;
        bool enabledAction;
        bool enabledAuth;
        bool enabledAdminActions;

    private:
        LoggingDaemon();
        ~LoggingDaemon();
        
    public:
        static LoggingDaemon* getInstance();
        void logAction(const std::string& action);
        void logAuth(User* user);
        bool getEnabledAction();
        bool getEnabledAuth();
        bool getEnabledAdminActions();
        void setEnabledAction(bool value);
        void setEnabledAuth(bool value);
        void setEnabledAdminActions(bool value);
    };

#endif
