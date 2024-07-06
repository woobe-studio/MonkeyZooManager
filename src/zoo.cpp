#include "monkey.hpp"

namespace Monkey
{
	Zoo::Zoo()
	{
		AuthDaemon *authenticationDaemon = AuthDaemon::getInstance();
		this->setUniqueId(authenticationDaemon->getRandomUUID());
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
	UUIDv4::UUID Zoo::getUniqueId()
	{
		return this->uniqueId;
	}
	Space *Zoo::getSpace(long unsigned int countInVector)
	{
		if (countInVector < this->spaces.size())
			return (this->spaces)[countInVector];
		else
			return nullptr;
	}

	void Zoo::addSpace(Space *spaceToAdd)
	{
		spaces.push_back(spaceToAdd);
	}

	int Zoo::getSpaceCount()
	{
		return spaces.size();
	}
	void Zoo::setUniqueId(UUIDv4::UUID newUuid)
	{
		this->uniqueId = newUuid;
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
