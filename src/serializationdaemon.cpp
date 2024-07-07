#include "monkey.hpp"

namespace Monkey
{
	SerializationDaemon *SerializationDaemon::instance = nullptr;
	SerializationDaemon::SerializationDaemon()
	{
	}
	SerializationDaemon::~SerializationDaemon()
	{
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
		if (!this->zooByName(newZoo->getZooName()))
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

	void save();
	void load();
}
