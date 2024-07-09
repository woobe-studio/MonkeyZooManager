#include "monkey.hpp"

namespace Monkey
{
	AuthDaemon *AuthDaemon::instance = nullptr;
	AuthDaemon::AuthDaemon()
	{
		loggedInUser = nullptr;
	}

	AuthDaemon::~AuthDaemon()
	{
		for (User *user : users)
		{
			delete user;
		}
		users.clear();
	}

	AuthDaemon *AuthDaemon::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new AuthDaemon();
		}
		return instance;
	}

	void AuthDaemon::destroyDaemon()
	{
		if (instance)
			delete instance;
		instance = nullptr;
	}

	bool AuthDaemon::login(const std::string &username, const std::string &password)
	{
		std::vector<User *>::iterator iterUsers = users.begin();
		while (iterUsers != users.end())
		{
			if (username == ((users)[iterUsers - users.begin()])->getUsername() && ((users)[iterUsers - users.begin()])->checkPassword(password))
			{
				this->loggedInUser = ((users)[iterUsers - users.begin()]);
				return true;
			}
			else
				iterUsers++;
		}
		return false;
	}

	void AuthDaemon::logout() { this->loggedInUser = nullptr; }
	bool AuthDaemon::isLoggedIn(User *user) { return (this->loggedInUser) ? true : false; }
	bool AuthDaemon::isLoggedInUserAdmin() { return (this->loggedInUser->getAccType() == userType::ADMIN) ? true : false; }
	bool AuthDaemon::doesUsernameExist(std::string username)
	{
		std::vector<User *>::iterator iterUsers = this->users.begin();
		while (iterUsers != this->users.end())
		{
			if (!(((users)[iterUsers - this->users.begin()])->getUsername() == username))
			{
				return true;
			}
			else
				iterUsers++;
		}
		return false;
	}

	User *AuthDaemon::retPointerOfUsername(std::string username)
	{
		std::vector<User *>::iterator iterUsers = this->users.begin();
		while (iterUsers != this->users.end())
		{
			if (!(((users)[iterUsers - this->users.begin()])->getUsername() == username))
			{
				return (users)[iterUsers - this->users.begin()];
			}
			iterUsers++;
		}
		return nullptr;
	}

	User *AuthDaemon::retPointerOfLoggedInUser()
	{
		return this->loggedInUser;
	}

	void AuthDaemon::addUser(User *user)
	{
		if (!this->doesUsernameExist(user->getUsername()))
		{
			this->users.push_back(user);
		}
	}

	void AuthDaemon::remUser(User *user)
	{
		std::vector<User *>::iterator iterUsers = this->users.begin();
		while (iterUsers != this->users.end())
		{
			if (user->getUsername() == ((users)[iterUsers - this->users.begin()])->getUsername())
			{
				iterUsers = this->users.erase(iterUsers);
			}
			else
				iterUsers++;
		}
	}

	void AuthDaemon::remUser(std::string userToDel)
	{
		User *temp = this->retPointerOfUsername(userToDel);
		if (temp)
			this->remUser(temp);
	}

	void AuthDaemon::to_json(json &j) const
	{
		json usersJson;
		for (const auto &tempUser : this->users)
		{
			json oneUserJson;
			tempUser->to_json(oneUserJson);
			usersJson.push_back(oneUserJson);
		}
		j["users"] = usersJson;
	}

	void AuthDaemon::from_json(const json &j)
	{
		const auto &usersJson = j.at("users");
		for (const auto &oneUserJson : usersJson)
		{
			User *tempUser = new User();
			tempUser->from_json(oneUserJson);
			users.push_back(tempUser);
		}
	}
}
