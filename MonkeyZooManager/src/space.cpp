#include "monkey.hpp"
#include <stdexcept>

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

	void Space::to_json(json &j) const
	{
		j = json{{"capacity", capacity}};
		json animalsJson;
		for (const auto &animal : animals)
		{
			json animalJson;
			animal->to_json(animalJson);
			animalsJson.push_back(animalJson);
		}
		j["animals"] = animalsJson;
	}

	void Space::from_json(const json &j)
	{
		capacity = j.at("capacity").get<int>();

		const auto &animalsJson = j.at("animals");
		for (const auto &animalJson : animalsJson)
		{
			Animal *animal = nullptr;
			std::string mainType = animalJson.at("animalType").get<std::string>();
			if (mainType == "Monkey")
			{
				std::string animalType = animalJson.at("MonkeyType").get<std::string>();

				if (animalType == "DartMonkey")
				{
					animal = new DartMonkey();
				}
				else if (animalType == "StudentMonkey")
				{
					animal = new StudentMonkey();
				}
				else if (animalType == "GalacticMonkey")
				{
					animal = new GalacticMonkey();
				}
				else if (animalType == "HeisenMonkey")
				{
					animal = new HeisenMonkey();
				}
				else if (animalType == "LavaMonkey")
				{
					animal = new LavaMonkey();
				}
				else
				{
					throw std::invalid_argument("Received invalid monkey inside JSON DESERIALIZATION. Type: " + animalType);
				}
			}
			else
			{

				throw std::invalid_argument("Received invalid animal inside JSON DESERIALIZATION. Type: " + mainType);
			}

			if (animal != nullptr)
			{
				animal->setSpace(this);
				animal->from_json(animalJson);
				this->animals.push_back(animal);
			}
			else
			{

				for (const auto &animal : this->animals)
				{
					delete animal;
				}
				throw std::runtime_error("Allocation error - got nullptr at JSON DESERIALIZATION");
			}
		}
	}

}
