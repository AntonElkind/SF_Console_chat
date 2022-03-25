#include "chat.h"
#include <iostream>
#include <string>

Chat::Chat() : _loggedUserIndex(-1)
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
			std::cout << "Registration aborted" << std::endl << std::endl;
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
				_members[i].setOnline(true);
				_loggedUserIndex = i;
				return 0;
			}
			std::cout << "Wrong password!" << std::endl;
			return -1;
		}
	}
	std::cout << "User with email " << userIn << " is not registered" << std::endl;
	return -1;
}

void Chat::logOut()
{
	_members[_loggedUserIndex].setOnline(false);
	_loggedUserIndex = -1;
}

int Chat::sendMessage(const std::string& to, const std::string& text)
{
	int id = nameToID(to);
	if (id < 0)
	{
		std::cout << "User does not exist" << std::endl;
		return -1;
	}
	_members[id].putMessage(_members[_loggedUserIndex].getName(), text);
	return 0;
}

void Chat::run()
{
	std::string userIn;
	bool chatRunning = true;

	while (chatRunning)
	{
		prompt();
		std::cin >> userIn;
		if (userIn.length() > 1)
		{
			userIn.clear();
		}
		if (_loggedUserIndex < 0)
		{
			switch (userIn[0])
			{
			case 'r':
				if (registration() == 0)
				{
					std::cout << "Successfully registered" << std::endl << std::endl;
				}
				break;

			case 'l':
				if (logIn() == 0)
				{
					std::cout << "Successfully logged in" << std::endl << std::endl;
				}
				else
				{
					std::cout << "Log in failed" << std::endl << std::endl;
				}
				break;

			case 'x':
				std::cout << "Exit" << std::endl;
				chatRunning = false;
				break;

			default:
				std::cout << "Unknown command" << std::endl << std::endl;
			}
		}
		else
		{
			switch (userIn[0])
			{
			case 'q':
				logOut();
				std::cout << "Logged out" << std::endl << std::endl;
				break;

			case 's':
			{
				if (_members.getLength() == 1)
				{
					std::cout << "Only you in this chat :(" << std::endl << std::endl;
					break;
				}
				std::cout << "Registered users:" << std::endl;
				for (int i = 0; i < _members.getLength(); ++i)
				{
					if (i == _loggedUserIndex)
					{
						continue;
					}
					std::cout << _members[i].getName() << std::endl;
				}
				std::cout << "Select user name or enter -all to send to everyone: ";
				std::string name;
				std::cin >> name;
				std::cout << "Write message: ";
				std::string msg;
				std::cin >> msg;
				if (name.compare("-all") == 0)
				{
					for (int i = 0; i < _members.getLength(); ++i)
					{
						if (i == _loggedUserIndex)
						{
							continue;
						}
						sendMessage(_members[i].getName(), msg);
					}
					std::cout << "Successfully sent to all members" << std::endl << std::endl;
				}
				else
				{
					if (sendMessage(name, msg) == 0)
					{
						std::cout << "Successfully sent" << std::endl << std::endl;
					}
				}
				break;
			}
			case 'l':
				std::cout << "Last received message:" << std::endl;
				_members[_loggedUserIndex].printLast();
				break;

			case 'a':
				std::cout << "Inbox:" << std::endl;
				_members[_loggedUserIndex].printAll();
				break;

			default:
				std::cout << "Unknown command" << std::endl << std::endl;
			}
		}
	}
}

int Chat::nameToID(const std::string& name)
{
	for (int i = 0; i < _members.getLength(); ++i)
	{
		if (i == _loggedUserIndex)
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

void Chat::prompt()
{
	if (_loggedUserIndex < 0)
	{
		std::cout << "To registration enter 'r'," << std::endl;
		std::cout << "to log in enter 'l'," << std::endl;
		std::cout << "to exit enter 'x'" << std::endl;
	}
	else
	{
		std::cout << "To log out enter 'q'," << std::endl;
		std::cout << "to send message enter 's'," << std::endl;
		std::cout << "to print last message enter 'l'," << std::endl;
		std::cout << "to print all messages enter 'a'," << std::endl;
	}
}
