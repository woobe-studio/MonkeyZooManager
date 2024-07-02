#include "monke.hpp"

namespace Monke{
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

userType User::getAccType(){
	return this->accType;
}


std::string User::getUsername(){
	return this->username;
}

Zoo* User::getZoo(){
	return this->accessToZoo;
}

bool User::checkPassword(const std::string& providedPassword){
	return bcrypt::validatePassword(providedPassword, this->hashOfPassword);
}

//sets
void User::setZoo(Zoo *newZoo){
	this->accessToZoo=newZoo;
}


void User::setUsername(const std::string& newUsername){
	this->username=newUsername;
}


void User::setPassword(const std::string& newPassword){
	this->hashOfPassword=bcrypt::generateHash(newPassword, 5);
}

void User::setPassword(const std::string& newPassword, int bcryptIterations){
	this->hashOfPassword=bcrypt::generateHash(newPassword, bcryptIterations);
}
}