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

	void Note::to_json(json &j) const
	{
		j["date_saved"] = (this->date) ? true : false;
		if (this->date)
		{
			j["date_hour"] = this->date->tm_hour;
			j["date_min"] = this->date->tm_min;
			j["date_sec"] = this->date->tm_sec;
			j["date_mday"] = this->date->tm_mday;
			j["date_month"] = this->date->tm_mon;
			j["date_year"] = this->date->tm_year;
		}
		j["text"] = this->text;
	}
	void Note::from_json(const json &j)
	{
		if (j.at("date_saved").get<bool>())
		{
			date = new tm;
			date->tm_hour = j.at("date_hour").get<int>();
			date->tm_min = j.at("date_min").get<int>();
			date->tm_sec = j.at("date_sec").get<int>();
			date->tm_mday = j.at("date_mday").get<int>();
			date->tm_mon = j.at("date_month").get<int>();
			date->tm_year = j.at("date_year").get<int>();
		}
		else
		{
			date = nullptr;
		}
		text = j.at("text").get<std::string>();
	}
}
