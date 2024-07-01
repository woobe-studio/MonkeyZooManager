#include "monke.hpp"
#include <vector>

namespace Monke{
AuthDaemon* AuthDaemon::instance = nullptr;
LoggingDaemon* LoggingDaemon::instance = nullptr;

Zoo::Zoo(){
	std::vector<Space*> spaces;
}
Zoo::~Zoo(){
	for (auto iterSpaces : spaces){
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
	if(newCapacity<this->count)
		return 1;
	else{
		this->count=newCapacity;
		return 0;
	}
}

int Space::getCapacity(){return this->capacity;}

int Space::addAnimal(Animal *animal){animals.push_back(animal); return 0;}
int Space::removeAnimal(Animal *animal){return -15;}
int Space::getCount(){return this->animals.size();}

bool Space::isFull(){
	return (this->capacity<=this->getCount())? true : false;
}

bool Space::isEmpty(){
	return (this->getCount())? false : true;
}

Animal::Animal(){
	space=nullptr;
}

Animal::~Animal(){
}

void Animal::setSpace(Space *newSpace){this->space=newSpace;}
void Animal::setAge(int animalAge){this->age=animalAge;}
void Animal::setName(const std::string &animalName){this->name.assign(animalName);}
void Animal::setRarity(Rarity animalRarity){this->rarity=animalRarity;}
Space* Animal::getSpace(){return this->space;};
std::string Animal::getName(){return this->name;}
int Animal::getAge(){return this->age;}
Rarity Animal::getRarity(){return this->rarity;}
void Animal::addNote(Note *newNote){}
int Animal::removeNote(Note *noteToRemove){return -15;}


User::User(){
	this->accType=userType::STANDARD;
	this->accessToZoo=nullptr;
}

User::User(std::string iusername, std::string ipassword, userType iaccType, Zoo* izoo){
	this->username=iusername;
	this->setPassword(ipassword);
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
	this->username=newUsername;
}

bool User::checkPassword(const std::string& providedPassword){
	return bcrypt::validatePassword(providedPassword, this->password);
}

void User::setPassword(const std::string& newPassword){
	this->password=bcrypt::generateHash(newPassword);
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
AuthDaemon::AuthDaemon(){
	loggedInUser = nullptr;
}

AuthDaemon::~AuthDaemon(){
	for (User* user : users) {
		delete user;
	}
	users.clear();
}


int AuthDaemon::forceLogin(User* user){
	if(user!=nullptr){
		this->loggedInUser=user;
		return 0;
	}
	return 1;
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
		if(username==((users)[iterUsers-users.begin()])->getUsername() and ((users)[iterUsers-users.begin()])->checkPassword(password)){
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

	bool AuthDaemon::doesUsernameExist(std::string username){
		std::vector<User*>::iterator iterUsers = this->users.begin();
		while(iterUsers != this->users.end()){
			if(!(((users)[iterUsers-this->users.begin()])->getUsername().compare(username))){
				return true;
			}
			iterUsers++;
		}
		return false;
	}

	int AuthDaemon::addUser(User* user){
		if(!this->doesUsernameExist(user->getUsername())){
			try {
				this->users.push_back(user);
			} catch (...) {
				return -20;
			}
			return 0;
		}
		return -12;
	}

	int AuthDaemon::remUser(User* user){
		std::vector<User*>::iterator iterUsers = this->users.begin();
		while(iterUsers != this->users.end()){
			if(user->getUsername()==((users)[iterUsers-this->users.begin()])->getUsername()){
				try {
					iterUsers=this->users.erase(iterUsers);
				} catch (...) {
					iterUsers++;
					return -20;
				}
				return 0;
			}
			iterUsers++;
		}
		return -5;
	}


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
void LoggingDaemon::logAuth(User* user, const std::string& action){}
void LoggingDaemon::logAdminAction(User* user, const std::string& action){};
bool LoggingDaemon::getEnabledAction(){return this->enabledAction;}
bool LoggingDaemon::getEnabledAuth(){return this->enabledAuth;}
bool LoggingDaemon::getEnabledAdminAction(){return this->enabledAdminActions;}
void LoggingDaemon::setEnabledAction(bool value){this->enabledAction=value;}
void LoggingDaemon::setEnabledAuth(bool value){this->enabledAuth=value;}
void LoggingDaemon::setEnabledAdminAction(bool value){this->enabledAdminActions=value;}
}
