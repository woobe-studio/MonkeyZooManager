#include "monkey.hpp"
#include <algorithm>

namespace Monkey
{
	Note::Note()
	{
		this->animal = nullptr;
		this->date = nullptr;
	}

	Note::~Note()
	{
		if (this->date)
			delete this->date;
	}

	Animal *Note::getAnimal() { return this->animal; }
	tm *Note::getDate() { return this->date; }
	std::string Note::getNote() { return this->text; }

	int Note::setNote(const std::string &newNote)
	{
		this->text = newNote;
		return 0;
	}

	int Note::setAnimal(Animal *connectedAnimal)
	{
		if (connectedAnimal)
		{
			this->animal = connectedAnimal;
			return 0;
		}
		else
		{
			return -99;
		}
	}

	int Note::setTimeNow()
	{
		if (this->date != nullptr)
			delete this->date;
		this->date = TimeDaemon::getNewTimePointerNow();
		return 0;
	}

	int Note::setTime(tm *newLtm)
	{
		if (this->date != nullptr)
			delete this->date;
		this->date = TimeDaemon::copyTimefromTimePointer(newLtm);
		return 0;
	}

	void Note::to_json(json &j) const {}
	void Note::from_json(const json &j) {}
}
