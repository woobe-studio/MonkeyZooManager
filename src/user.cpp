#include "monkey.hpp"

namespace Monkey
{
	User::User()
	{
		this->username = "nullNewUser";
		this->accType = userType::STANDARD;
		this->accessToZoo = nullptr;
	}

	User::User(const std::string &iusername, const std::string &ipassword, userType iaccType, Zoo *izoo)
	{
		this->username = iusername;
		this->setPassword(ipassword);
		this->accType = iaccType;
		this->accessToZoo = izoo;
	}

	User::~User()
	{
	}

	userType User::getAccType()
	{
		return this->accType;
	}

	std::string User::getUsername()
	{
		return this->username;
	}

	Zoo *User::getZoo()
	{
		return this->accessToZoo;
	}

	bool User::checkPassword(const std::string &providedPassword)
	{
		return bcrypt::validatePassword(providedPassword, this->hashOfPassword);
	}

	void User::setZoo(Zoo *newZoo)
	{
		this->accessToZoo = newZoo;
	}

	void User::setUsername(const std::string &newUsername)
	{
		this->username = newUsername;
	}

	void User::setPassword(const std::string &newPassword)
	{
		this->hashOfPassword = bcrypt::generateHash(newPassword, 10);
	}

	void User::setPassword(const std::string &newPassword, int bcryptIterations)
	{
		this->hashOfPassword = bcrypt::generateHash(newPassword, bcryptIterations);
	}

	void User::to_json(json &j) const
	{

		j = json{{"username", this->username}, {"password", this->hashOfPassword}};
		json typeJson = static_cast<int>(this->accType);
		j["accType"] = typeJson;
		if (accessToZoo != nullptr)
		{
			j["accessToZoo"] = accessToZoo->getZooName();
		}
		else
		{
			j["accessToZoo"] = "";
		}
	}

	void User::from_json(const json &j)
	{
		this->username = j.at("username").get<std::string>();
		this->hashOfPassword = j.at("password").get<std::string>();
		this->accType = static_cast<userType>(j["accType"].get<int>());
		std::string zooName = j["accessToZoo"].get<std::string>();
		Monkey::SerializationDaemon *serial = Monkey::SerializationDaemon::getInstance();
		Zoo *tmpZooAddr = serial->zooByName(zooName);
		if (tmpZooAddr != nullptr)
			this->accessToZoo = tmpZooAddr;
	}
}
