#include "monkey.hpp"

namespace Monkey
{

	Animal::Animal()
	{
		this->space = nullptr;
		this->rarity = Rarity::COMMON;
		this->age = 1;
		this->name = "noName";
	}

	Animal::~Animal()
	{
		for (auto i : this->notes)
		{
			if (i)
				delete i;
		}
	}

	void Animal::setSpace(Space *newSpace) { this->space = newSpace; }
	void Animal::setAge(int animalAge) { this->age = animalAge; }
	void Animal::setName(const std::string &animalName) { this->name.assign(animalName); }
	void Animal::setRarity(Rarity animalRarity) { this->rarity = animalRarity; }

	Space *Animal::getSpace() { return this->space; }
	std::string Animal::getName() { return this->name; }
	int Animal::getAge() { return this->age; }
	Rarity Animal::getRarity() { return this->rarity; }

	void Animal::addNote(Note *newNote)
	{
		this->notes.push_back(newNote);
		if (newNote)
		{
			try
			{
				newNote->setAnimal(this);
			}
			catch (...)
			{
			}
		}
	}
	void Animal::removeNote(Note *noteToRemove)
	{
		std::vector<Note *>::iterator iterVec = this->notes.begin();
		while (iterVec != this->notes.end())
		{
			if (noteToRemove == (this->notes)[iterVec - this->notes.begin()])
			{
				iterVec = this->notes.erase(iterVec);
			}
			else
				iterVec++;
		}
	}

	void Animal::to_json(json &j) const
	{
		j["name"] = this->name;
		j["age"] = this->age;
		j["notes"] = json::array();
		json rarityJson = static_cast<int>(this->rarity);
		j["rarity"] = rarityJson;
		json &notesJson = j["notes"];
		for (const auto &note : notes)
		{
			json noteJson;
			note->to_json(noteJson);
			notesJson.push_back(noteJson);
		}
	}

	void Animal::from_json(const json &j)
	{
		this->name = j.at("name").get<std::string>();
		this->age = j.at("age").get<int>();
		this->rarity = static_cast<Rarity>(j.at("rarity").get<int>());

		const auto &notesJson = j.at("notes");
		for (const auto &noteJson : notesJson)
		{
			std::string noteType = noteJson.at("noteType").get<std::string>();
			Note *note = nullptr;

			if (noteType == "MedicalNote")
			{
				note = new MedicalNote();
			}
			else if (noteType == "OtherNote")
			{
				note = new OtherNote();
			}
			else if (noteType == "BehavioralNote")
			{
				note = new BehavioralNote();
			}
			else
			{
				note = new Note();
			}

			if (note != nullptr)
			{
				note->setAnimal(this);
				note->from_json(noteJson);
				notes.push_back(note);
			}
		}
	}
}
