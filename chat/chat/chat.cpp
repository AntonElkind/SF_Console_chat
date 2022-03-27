#include "chat.h"
#include <iostream>
#include <string>

Chat::Chat()
{
	_loggedUserEmail.clear();
}

int Chat::registration()
{
	ChatMember tempMember;
	std::string userIn;

	std::cout << "Enter your email: ";
	std::cin >> userIn;
	auto it = _members.find(userIn);
	if (it != _members.end())
	{
		std::cout << "User with email " << userIn << " already exists" << std::endl;
		std::cout << "Registration aborted" << std::endl << std::endl;
		return -1;
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
	
	tempMember.setID(_members.size());
	_members.insert({ tempMember.getEmail(), tempMember });
	return 0;
}

int Chat::logIn()
{
	std::string userIn;

	std::cout << "Enter email: ";
	std::cin >> userIn;
	auto it = _members.find(userIn);
	if (it != _members.end())
	{
		userIn.clear();
		std::cout << "Enter password: ";
		std::cin >> userIn;
		if (userIn.compare(it->second.getPassword()) == 0)
		{
			it->second.setOnline(true);
			_loggedUserEmail = it->first;
			return 0;
		}
		std::cout << "Wrong password!" << std::endl;
		return -1;
	}
	std::cout << "User with email " << userIn << " is not registered" << std::endl;
	return -1;
}

void Chat::logOut()
{
	_members[_loggedUserEmail].setOnline(false);
	_loggedUserEmail.clear();
}

int Chat::sendMessage(const std::string& to, const std::string& text)
{
	for (auto& it : _members)
	{
		if (to.compare(it.second.getName()) == 0)
		{
			it.second.putMessage(_loggedUserEmail, text);
			return 0;
		}
	}
	std::cout << "User does not exist" << std::endl;
	return -1;
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
		if (_loggedUserEmail.empty())
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
				if (_members.size() == 1)
				{
					std::cout << "Only you in this chat :(" << std::endl << std::endl;
					break;
				}
				std::cout << "Registered users:" << std::endl;
				for (auto& it : _members)
				{
					if (it.first == _loggedUserEmail)
					{
						continue;
					}
					std::cout << it.second.getName() << std::endl;
				}
				std::cout << "Select user name or enter -all to send to everyone: ";
				std::string name;
				std::cin >> name;
				std::cout << "Write message: ";
				std::string msg;
				std::cin >> msg;
				if (name.compare("-all") == 0)
				{
					for (auto& it : _members)
					{
						if (it.first == _loggedUserEmail)
						{
							continue;
						}
						sendMessage(it.second.getName(), msg);
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
			{
				std::cout << "Last received message:" << std::endl;
				auto member = _members.find(_loggedUserEmail);
				member->second.printLast();
				break;
			}
			case 'a':
			{
				std::cout << "Inbox:" << std::endl;
				auto member = _members.find(_loggedUserEmail);
				member->second.printAll();
				break;
			}
			default:
				std::cout << "Unknown command" << std::endl << std::endl;
			}
		}
	}
}

void Chat::prompt()
{
	if (_loggedUserEmail.empty())
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
