#include "monke.hpp"

namespace Monke
{
	Space::Space()
	{
		std::vector<Animal *> animals;
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
	Animal *Space::getAnimal(int countInVector)
	{
		if (countInVector >= 0 && countInVector < this->animals.size())
			return (this->animals)[countInVector];
		else
			return nullptr;
	}
	int Space::getCount() { return this->animals.size(); }

	int Space::setCapacity(int newCapacity)
	{
		if (newCapacity < this->getCount())
			return 1;
		else
		{
			this->capacity = newCapacity;
			return 0;
		}
	}

	int Space::addAnimal(Animal *animal)
	{
		try
		{
			animals.push_back(animal);
		}
		catch (...)
		{
			return -12;
		}
		return 0;
	}

	int Space::removeAnimal(Animal *animalToRemove)
	{
		std::vector<Animal *>::iterator iterVec = this->animals.begin();
		while (iterVec != this->animals.end())
		{
			if (animalToRemove == (this->animals)[iterVec - this->animals.begin()])
			{
				try
				{
					iterVec = this->animals.erase(iterVec);
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

	bool Space::isFull()
	{
		return (this->capacity <= this->getCount()) ? true : false;
	}

	bool Space::isEmpty()
	{
		return (this->getCount()) ? false : true;
	}
}
