#include "monke.hpp"

namespace Monke
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

	int Zoo::setZooName(std::string newName)
	{
		this->name = newName;
		return 0;
	}

	std::string Zoo::getZooName()
	{
		return this->name;
	}

	int Zoo::addSpace(Space *spaceToAdd)
	{
		try
		{
			spaces.push_back(spaceToAdd);
		}
		catch (...)
		{
			return -20;
		}
		return 0;
	}

	int Zoo::removeSpace(Space *spaceToRemove)
	{
		std::vector<Space *>::iterator iterSpaces = spaces.begin();
		while (iterSpaces != spaces.end())
		{
			if (spaceToRemove == (spaces)[iterSpaces - spaces.begin()])
			{
				try
				{
					(spaces).erase(iterSpaces);
				}
				catch (...)
				{
					return -20;
				}
				return 0;
			}
			iterSpaces++;
		}
		return -6;
	}

}
