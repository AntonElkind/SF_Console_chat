#include "chat.h"
#include <iostream>
#include <string>

Chat::Chat() : loggedUserIndex(-1)
{
}

int Chat::registration()
{
	ChatMember tempMember;
	std::string userIn;

	std::cout << "Enter your email: ";
	std::cin >> userIn;
	for (int i = 0; i < _members.getLength(); ++i)
	{
		if (userIn.compare(_members[i].getEmail()) == 0)
		{
			std::cout << "User with email " << userIn << " already exists" << std::endl;
			std::cout << "Registration aborted" << std::endl;
			return -1;
		}
	}
	tempMember.setEmail(userIn);

	userIn.clear();
	std::cout << "Enter your name: ";
	std::cin >> userIn;
	tempMember.setName(userIn);

	userIn.clear();
	std::cout << "Enter your password: ";
	std::cin >> userIn;
	tempMember.setPassword(userIn);
	
	tempMember.setID(_members.getLength());
	_members.add(tempMember);
	return 0;
}

int Chat::logIn()
{
	std::string userIn;

	std::cout << "Enter email: ";
	std::cin >> userIn;
	for (int i = 0; i < _members.getLength(); ++i)
	{
		if (userIn.compare(_members[i].getEmail()) == 0)
		{
			userIn.clear();
			std::cout << "Enter password: ";
			std::cin >> userIn;
			if (userIn.compare(_members[i].getPassword()) == 0)
			{
				std::cout << "Logged in" << std::endl;
				_members[i].setOnline(true);
				loggedUserIndex = i;
				return 0;
			}
			std::cout << "Wrong password!" << std::endl;
			return -1;
		}
	}
	std::cout << "User with email " << userIn << " is not registered" << std::endl;
	std::cout << "Log in failed" << std::endl;
	return -1;
}

void Chat::logOut()
{
	_members[loggedUserIndex].setOnline(false);
	std::cout << "Logged out" << std::endl;
}

int Chat::sendMessage(const std::string& to, const std::string& text)
{
	int id = nameToID(to);
	if (id < 0)
	{
		std::cout << "User does not exist" << std::endl;
		return -1;
	}
	_members[id].putMessage(_members[loggedUserIndex].getName(), text);
	return 0;
}

int Chat::nameToID(const std::string& name)
{
	for (int i = 0; i < _members.getLength(); ++i)
	{
		if (i == loggedUserIndex)
		{
			continue;
		}
		if (name.compare(_members[i].getName()) == 0)
		{
			return _members[i].getID();
		}
	}
	return -1;
}
