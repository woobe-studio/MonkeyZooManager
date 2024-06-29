#include "monke.hpp"
#include <cstdio>
#include <functional>
#include <string>

AuthDaemon* AuthDaemon::instance = nullptr;
LoggingDaemon* LoggingDaemon::instance = nullptr;

Zoo::Zoo(){
	std::vector<Space*> spaces;
}
Zoo::~Zoo(){
	for (auto iterSpaces : spaces) {
		delete iterSpaces;
	}
}

int Zoo::setZooName(std::string newName){
	this->name.assign(newName);
	return 0;
}

std::string Zoo::getZooName(){
	return this->name;
}

int Zoo::addSpace(Space *spaceToAdd){
	try{
		spaces.push_back(spaceToAdd);
	}
	catch(...) {
		return -20;
	}
	return 0;
}

int Zoo::removeSpace(Space *spaceToRemove){
	std::vector<Space*>::iterator iterSpaces = spaces.begin();
	while(iterSpaces != spaces.end()){
		if(spaceToRemove==(spaces)[iterSpaces-spaces.begin()]){
			try{
			(spaces).erase(iterSpaces);
			} catch (...) {return -20;}
			return 0;
		}
		iterSpaces++;
	}
	return -6;
}

Space::Space(){
	std::vector<Animal*> animals;
}

Space::~Space(){
	for (auto iterAnimals : animals) {
		delete iterAnimals;
	}
}

int Space::setCapacity(int newCapacity){
	if(newCapacity<count)
		return 1;
	else{
		count=newCapacity;
		return 0;
	}
}

int Space::getCapacity(){return -15;}

int Space::addAnimal(Animal *animal){return -15;}
int Space::removeAnimal(Animal *animal){return -15;}
int Space::getCount(){return -15;}

Animal::Animal(){
	space=nullptr;
}

Animal::~Animal(){
}

void Animal::setSpace(Space *zoo){}
void Animal::setAge(int animalAge){}
void Animal::setName(const std::string &animalName){this->name.assign(animalName);}
void Animal::setRarity(Rarity animalRarity){this->rarity=animalRarity;}
Space* Animal::getSpace(){return this->space;};
std::string Animal::getName(){return this->name;}
int Animal::getAge(){return this->age;}
Rarity Animal::getRarity(){return this->rarity;}
void Animal::addNote(Note *newNote){}
int Animal::removeNote(Note *noteToRemove){return -15;}

User::User(){
	this->accType=0;
	this->accessToZoo=nullptr;
}

User::User(std::string iusername, std::string ipassword, int iaccType, Zoo* izoo){
	this->username.assign(iusername);
	this->password.assign(ipassword);
	this->accType=iaccType;
	this->accessToZoo=izoo;
}

User::~User(){
}

void User::setZoo(Zoo *newZoo){
	this->accessToZoo=newZoo;
}


std::string User::getUsername(){
	return this->username;
}

void User::setUsername(const std::string& newUsername){
	this->username.assign(newUsername);
}

std::string User::getPassword(){
	return this->password;
}

void User::setPassword(const std::string& newPassword){
	this->password.assign(newPassword);
}

Zoo* User::getZoo(){
	return this->accessToZoo;
}

Note::Note(){
	this->animal=nullptr;
}

Note::~Note(){

}

Animal* Note::getAnimal(){return this->animal;}
long Note::getDate(){return this->date;}
std::string Note::getNote(){return this->note;}
//AuthDaemon
AuthDaemon::AuthDaemon(){
	loggedInUser = nullptr;
}

AuthDaemon::~AuthDaemon(){
	for (User* user : users) {
		delete user;
	}
	users.clear();
}


int AuthDaemon::login(User* user){
	return 0;
}

AuthDaemon* AuthDaemon::getInstance(){
        if (instance == nullptr) {
		instance = new AuthDaemon();
        }
        return instance;
    }

void AuthDaemon::destroyDaemon(){
	if(instance)
		delete instance;
    instance = nullptr;
}

int AuthDaemon::login(const std::string& username, const std::string& password){
	std::vector<User*>::iterator iterUsers = users.begin();
	while(iterUsers != users.end()){
		if(username==((users)[iterUsers-users.begin()])->getUsername() and password==((users)[iterUsers-users.begin()])->getPassword()){
			this->loggedInUser=((users)[iterUsers-users.begin()]);
			return 0;
		}
		iterUsers++;
	}
	return -5;
}

	void AuthDaemon::logout(){this->loggedInUser=nullptr;};
        bool AuthDaemon::isLoggedIn(User* user){return true;}
        bool AuthDaemon::isLoggedInUserAdmin() {return false;}
        void AuthDaemon::addUser(User* user){}
        void AuthDaemon::remUser(User* user){}

LoggingDaemon::LoggingDaemon(){
	this->enabledAuth=true;
	this->enabledAction=true;
	this->enabledAdminActions=true;
}

LoggingDaemon::~LoggingDaemon(){

}

LoggingDaemon* LoggingDaemon::getInstance(){
        if (instance == nullptr) {
		instance = new LoggingDaemon();
        }
        return instance;
}

void LoggingDaemon::destroyDaemon(){
	if(instance)
		delete instance;
	instance = nullptr;
}


	void LoggingDaemon::logAction(const std::string& action){}
        void LoggingDaemon::logAuth(User* user){}
        bool LoggingDaemon::getEnabledAction(){return false;}
        bool LoggingDaemon::getEnabledAuth(){return false;}
        bool LoggingDaemon::getEnabledAdminActions(){return false;}
        void LoggingDaemon::setEnabledAction(bool value){}
        void LoggingDaemon::setEnabledAuth(bool value){}
        void LoggingDaemon::setEnabledAdminActions(bool value){}

