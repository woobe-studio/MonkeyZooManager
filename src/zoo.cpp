#include "monkey.hpp"

namespace Monkey
{
	Zoo::Zoo()
	{
		std::vector<Space *> spaces;
	}
	Zoo::~Zoo()
	{
		for (auto iterSpaces : spaces)
		{
			delete iterSpaces;
		}
	}

	void Zoo::setZooName(std::string newName)
	{
		this->name = newName;
	}

	std::string Zoo::getZooName()
	{
		return this->name;
	}

	void Zoo::addSpace(Space *spaceToAdd)
	{
		spaces.push_back(spaceToAdd);
	}

	void Zoo::removeSpace(Space *spaceToRemove)
	{
		std::vector<Space *>::iterator iterSpaces = spaces.begin();
		while (iterSpaces != spaces.end())
		{
			if (spaceToRemove == (spaces)[iterSpaces - spaces.begin()])
			{
				spaces.erase(iterSpaces);
			}
			iterSpaces++;
		}
	}

}
