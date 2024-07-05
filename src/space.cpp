#include "monkey.hpp"

namespace Monkey
{
	Space::Space()
	{
		this->capacity = 0;
	}

	Space::~Space()
	{
		for (auto iterAnimals : animals)
		{
			delete iterAnimals;
		}
	}

	int Space::getCapacity() { return this->capacity; }
	Animal *Space::getAnimal(long unsigned int countInVector)
	{
		if (countInVector < this->animals.size())
			return (this->animals)[countInVector];
		else
			return nullptr;
	}
	int Space::getCount() { return this->animals.size(); }

	bool Space::setCapacity(int newCapacity)
	{
		if (newCapacity < this->getCount())
			return true;
		else
		{
			this->capacity = newCapacity;
			return false;
		}
	}

	void Space::addAnimal(Animal *animal)
	{
		animals.push_back(animal);
	}

	void Space::removeAnimal(Animal *animalToRemove)
	{
		std::vector<Animal *>::iterator iterVec = this->animals.begin();
		while (iterVec != this->animals.end())
		{
			if (animalToRemove == (this->animals)[iterVec - this->animals.begin()])
			{
				iterVec = this->animals.erase(iterVec);
			}
			else
				iterVec++;
		}
	}

	bool Space::isFull()
	{
		return (this->capacity <= this->getCount()) ? true : false;
	}

	bool Space::isEmpty()
	{
		return (this->getCount()) ? false : true;
	}
}
