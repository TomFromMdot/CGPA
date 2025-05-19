#pragma once
#include <vector>
#include <iostream>
#include <optional>
#include "User.hpp"
class UserData
{
	std::vector<User*> users_;

public:
	UserData() {}
	~UserData() 
	{
		clearUsers();
	}
	void addNewUser(const std::string& username)
	{
		User* tmp = new User(username);
		users_.push_back(tmp);
	}

	void removeUser(const std::string& username)
	{
		for (auto it = users_.begin(); it != users_.end(); ++it)
		{
			if ((*it)->getName() == username)
			{
				users_.erase(it);
				users_.shrink_to_fit();
				return;
			}
		}
		std::cout << "Can't find user: " << username << "\n";
	}

	size_t getUsersCount()
	{
		return users_.size();
	}

	const std::vector<User*> getAllUsers() const
	{
		return users_;
	}

	std::optional<User*> getUserByName(const std::string& username)
	{
		for (auto* user : users_)
		{
			if (user->getName() == username)
			{
				return std::make_optional<User*>(user);
			}
		}
		std::cout << "Can't find user: " << username << "\n";
		return std::nullopt;
	}

	void addGradeToUser(const std::string& username,const std::string& subjectName, char sign, GradeType type, std::map<char, float> data)
	{
		for (auto* user : users_)
		{
			if (user->getName() == username)
			{
				user->addGradeWithPoint(subjectName, sign, type, data);
				return;
			}
		}
		std::cout << "Can't find user: " << username << "\n";
		return;
	}
private:
	void clearUsers()
	{
		if (users_.size() == 0)
			return;
		std::cout << "\n\nStart Cleaning users..\n";
		for (auto user : users_)
		{
			delete user;
		}
		users_.clear();
	}
};