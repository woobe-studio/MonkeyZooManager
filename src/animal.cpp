#include "monkey.hpp"

namespace Monkey
{

	Animal::Animal()
	{
		space = nullptr;
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
		j = json{{"name", this->name}, {"age", this->age}};
		json rarityJson = static_cast<int>(this->rarity);
		j["rarity"] = rarityJson;
	}

	void Animal::from_json(const json &j, Space *ptrSpace)
	{
		this->from_json(j);
		this->space = ptrSpace;
	}
	void Animal::from_json(const json &j)
	{
		this->name = j.at("name").get<std::string>();
		this->age = j.at("age").get<int>();
		this->rarity = static_cast<Rarity>(j["rarity"].get<int>());
		this->space = nullptr;
	}
