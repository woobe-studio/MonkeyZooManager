#include "monkey.hpp"
#include <fstream>

namespace Monkey
{
	SerializationDaemon *SerializationDaemon::instance = nullptr;
	SerializationDaemon::SerializationDaemon()
	{
	}
	SerializationDaemon::~SerializationDaemon()
	{
		for (auto i : this->zoos)
			delete i;
		AuthDaemon *authDaemon = AuthDaemon::getInstance();
		authDaemon->destroyDaemon();
	}
	SerializationDaemon *SerializationDaemon::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new SerializationDaemon();
		}
		return instance;
	}
	void SerializationDaemon::destroyDaemon()
	{
		if (instance)
			delete instance;
		instance = nullptr;
	}

	int SerializationDaemon::size()
	{
		return this->zoos.size();
	}
	Zoo *SerializationDaemon::zooByIndex(long unsigned int countInVector)
	{
		if (countInVector < this->zoos.size())
			return (this->zoos)[countInVector];
		else
			return nullptr;
	}
	Zoo *SerializationDaemon::zooByName(const std::string &uuid)
	{
		std::vector<Zoo *>::iterator iter = this->zoos.begin();
		while (iter != this->zoos.end())
		{
			if (!(((zoos)[iter - this->zoos.begin()])->getZooName() == uuid))
			{
				return (zoos)[iter - this->zoos.begin()];
			}
			else
				iter++;
		}
		return nullptr;
	}

	void SerializationDaemon::addZoo(Zoo *newZoo)
	{
		this->zoos.push_back(newZoo);
	}
	void SerializationDaemon::removeZoo(Zoo *toDelZoo)
	{
		std::vector<Zoo *>::iterator iter = this->zoos.begin();
		while (iter != this->zoos.end())
		{
			if (!(((zoos)[iter - this->zoos.begin()]) == toDelZoo))
			{
				iter = this->zoos.erase(iter);
			}
			else
				iter++;
		}
	}

	void SerializationDaemon::save()
	{
		json j;

		for (const auto &zoo : zoos)
		{
			json zooJson;
			zoo->to_json(zooJson);
			j["zoos"].push_back(zooJson);
		}

		AuthDaemon *authDaemon = AuthDaemon::getInstance();
		json authJson;
		authDaemon->to_json(authJson);
		j["authDaemon"] = authJson;

		std::ofstream file("serialization.json");
		file << j.dump(4);
		file.close();
	}

	void SerializationDaemon::load()
	{
		std::ifstream file("serialization.json");
		if (!file.is_open())
		{
			return;
		}

		json j;
		file >> j;
		file.close();

		if (j.contains("zoos") && j["zoos"].is_array())
		{
			for (const auto &zooJson : j["zoos"])
			{
				Zoo *zoo = new Zoo();
				zoo->from_json(zooJson);
				zoos.push_back(zoo);
			}
		}

		AuthDaemon *authDaemon = AuthDaemon::getInstance();
		if (j.contains("authDaemon"))
		{
			authDaemon->from_json(j["authDaemon"]);
		}
	}
}
