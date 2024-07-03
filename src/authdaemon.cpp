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

	int AuthDaemon::login(const std::string &username, const std::string &password)
	{
		std::vector<User *>::iterator iterUsers = users.begin();
		while (iterUsers != users.end())
		{
			if (username == ((users)[iterUsers - users.begin()])->getUsername() && ((users)[iterUsers - users.begin()])->checkPassword(password))
			{
				this->loggedInUser = ((users)[iterUsers - users.begin()]);
				return 0;
			}
			iterUsers++;
		}
		return -5;
	}

	void AuthDaemon::logout() { this->loggedInUser = nullptr; };
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

	int AuthDaemon::addUser(User *user)
	{
		if (!this->doesUsernameExist(user->getUsername()))
		{
			try
			{
				this->users.push_back(user);
			}
			catch (...)
			{
				return -20;
			}
			return 0;
		}
		return -12;
	}

	int AuthDaemon::remUser(User *user)
	{
		std::vector<User *>::iterator iterUsers = this->users.begin();
		while (iterUsers != this->users.end())
		{
			if (user->getUsername() == ((users)[iterUsers - this->users.begin()])->getUsername())
			{
				try
				{
					iterUsers = this->users.erase(iterUsers);
				}
				catch (...)
				{
					iterUsers++;
					return -20;
				}
				return 0;
			}
			iterUsers++;
		}
		return -5;
	}
}
