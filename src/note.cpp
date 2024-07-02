#include "monke.hpp"
#include <algorithm>


namespace Monke{
Note::Note(){
	this->animal=nullptr;
	this->date=nullptr;
}

Note::~Note(){
	if (this->date)
		delete this->date;
}

Animal* Note::getAnimal(){return this->animal;}
tm* Note::getDate(){return this->date;}
std::string Note::getNote(){return this->note;}


int Note::setNote(const std::string& newNote){
	this->note=newNote;
	return 0;
}

int Note::setAnimal(Animal* connectedAnimal){
	if(connectedAnimal){
		this->animal=connectedAnimal;
		return 0;
	}
	else {
		return -99;
	}
}

int Note::setTimeNow(){
	time_t now = time(0);
	tm* dt = localtime(&now);

	if (!this->date)
		this->date = new tm;

	memcpy(this->date, dt, sizeof(tm));

	return 0;
}

int Note::setTime(tm *newLtm){
	if (!this->date)
		this->date = new tm;
	memcpy(this->date, newLtm, sizeof(tm));
	return 0;
}
}
