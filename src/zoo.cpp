#include "monkey.hpp"

namespace Monkey
{
	Zoo::Zoo()
	{
		AuthDaemon *authenticationDaemon = AuthDaemon::getInstance();
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
	void Zoo::removeSpace(Space *spaceToRemove)
	{
		std::vector<Space *>::iterator iterSpaces = spaces.begin();
		while (iterSpaces != spaces.end())
		{
			if (spaceToRemove == (spaces)[iterSpaces - spaces.begin()])
			{
				iterSpaces = this->spaces.erase(iterSpaces);
			}
			else
				iterSpaces++;
		}
	}

	void Zoo::to_json(json &j) const
	{
		j = json{{"zooName", this->name}};

		json spacesJson;
		for (const auto &space : spaces)
		{
			json spaceJson;
			space->to_json(spaceJson);
			spacesJson.push_back(spaceJson);
		}
		j["spaces"] = spacesJson;
	}
	void Zoo::from_json(const json &j) {}

}
