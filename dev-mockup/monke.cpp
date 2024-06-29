#include "monke.hpp"
#include <cstdio>
#include <functional>
#include <string>


AuthDaemon* AuthDaemon::instance = nullptr;

Zoo::Zoo(){
	std::vector<Space*> spaces;
}
Zoo::~Zoo(){
	for (auto iterSpaces : spaces) {
		delete iterSpaces;
	}
}

int Zoo::setZooName(std::string newName){
	this->name=newName;
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
			(spaces).erase(iterSpaces);
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

void AuthDaemon::destroyDaemon() {
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

void logout(){};
        bool isLoggedIn(User* user){return true;}
        bool isLoggedInUserAdmin() {return false;}
        void addUser(User* user){}
        void remUser(User* user){}


	void logAction(const std::string& action);
        void logAuth(User* user);
        bool getEnabledAction();
        bool getEnabledAuth();
        bool getEnabledAdminActions();
        void setEnabledAction(bool value);
        void setEnabledAuth(bool value);
        void setEnabledAdminActions(bool value);
