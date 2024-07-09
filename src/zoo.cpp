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
		j = json{{"zooName", this->name}, {"spaces", json::array()}};

		json &spacesJson = j["spaces"];
		for (const auto &space : spaces)
		{
			if (space != nullptr)
			{
				json spaceJson;
				if (typeid(*space) == typeid(Cage))
				{
					spaceJson["spaceType"] = "Cage";
				}
				else if (typeid(*space) == typeid(Hospital))
				{
					spaceJson["spaceType"] = "Hospital";
				}
				else if (typeid(*space) == typeid(Enclosure))
				{
					spaceJson["spaceType"] = "Enclosure";
				}

				space->to_json(spaceJson);
				spacesJson.push_back(spaceJson);
			}
		}
	}

	void Zoo::from_json(const json &j)
	{
		try
		{
			this->name = j.at("zooName").get<std::string>();

			const auto &spacesJson = j.at("spaces");
			for (const auto &spaceJson : spacesJson)
			{
				std::string spaceType = spaceJson.at("spaceType").get<std::string>();

				Space *space = nullptr;
				if (spaceType == "Cage")
				{
					space = new Cage();
				}
				else if (spaceType == "Hospital")
				{
					space = new Hospital();
				}
				else if (spaceType == "Enclosure")
				{
					space = new Enclosure();
				}
				else
				{
				}

				if (space != nullptr)
				{
					space->from_json(spaceJson);
					spaces.push_back(space);
				}
			}
		}
		catch (const json::exception &e)
		{
		}
	}
}
