#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <string>
#include <streambuf>

class Space;
class Animal;

class Zoo{
	private:
	std::string name;
	std::vector<Space*> spaces;
	public:
	Zoo();
	~Zoo();
	int setZooName(std::string newName);
	std::string getZooName();
	int addSpace(Space* spaceToAdd);
	int removeSpace(Space* spaceToRemove);
};

class Space{
	protected:
	std::vector<Animal*> animals;
	int capacity;
	int count;

	public:
	virtual int addAnimal(Animal* animal);
	virtual int removeAnimal(Animal* animal);
	virtual int getCapacity();
	virtual int setCapacity(int newCapacity);
	virtual int getCount();
};

class Cage : public Space{};

class Hospital : public Space{};

class Enclosure : public Space{};
