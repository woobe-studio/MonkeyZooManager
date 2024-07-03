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

	Space *Animal::getSpace() { return this->space; };
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
	int Animal::removeNote(Note *noteToRemove)
	{
		std::vector<Note *>::iterator iterVec = this->notes.begin();
		while (iterVec != this->notes.end())
		{
			if (noteToRemove == (this->notes)[iterVec - this->notes.begin()])
			{
				try
				{
					iterVec = this->notes.erase(iterVec);
				}
				catch (...)
				{
					iterVec++;
					return -20;
				}
				return 0;
			}
			iterVec++;
		}
		return -12;
	}
}
