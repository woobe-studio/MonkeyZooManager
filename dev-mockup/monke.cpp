#include "monke.hpp"
#include <cstdio>
#include <functional>
#include <string>


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

int Space::setCapacity(int newCapacity){
	if(newCapacity<count)
		return 1;
	else{
		count=newCapacity;
		return 0;
	}
}

std::string User::getUsername(){
	return this->username;
}

void User::setUsername(std::string newUsername){
	this->username=newUsername;
}

std::string User::getPassword(){
	return this->password;
}

void User::setPassword(std::string newPassword){
	this->password=newPassword;
}

Zoo* User::getZoo(){
	return this->zoo;
}

AuthDaemon::AuthDaemon(){
	if (this->instance==NULL)
		this->instance=new AuthDaemon;
}

AuthDaemon::~AuthDaemon(){
	if (this->instance!=NULL){
		delete this->instance;
		this->instance=NULL;
	}
}

int AuthDaemon::login(User* user){
	std::vector<User*>::iterator iterUsers = users.begin();
	while(iterUsers != users.end()){
		if(user->username==((users)[iterSpaces-spaces.begin()])->username and user->password==((users)[iterSpaces-spaces.begin()])){
			this->loggedInUser=user;
			return 0;
		}
		iterSpaces++;
	}
	return -5;
}
