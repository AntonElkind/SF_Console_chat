#include "chatMember.h"
#include <iostream>

ChatMember::ChatMember() : _id(-1)
{
}

ChatMember::ChatMember(int id) : _id(id)
{
}

void ChatMember::setID(int id)
{
	_id = id;
}

int ChatMember::getID()
{
	return _id;
}

void ChatMember::putMessage(const std::string& sender, const std::string& text)
{
	Message msg{ sender, text };
	_mailBox.push_back(msg);
}

void ChatMember::printAll()
{
	if (_mailBox.empty() == true)
	{
		std::cout << "Mailbox empty" << std::endl << std::endl;
		return;
	}
	for (const auto& msg : _mailBox)
	{
		std::cout << "From:    " << msg.sender << std::endl;
		std::cout << "Message: " << msg.text << std::endl << std::endl;
	}
}

void ChatMember::printLast()
{
	if (_mailBox.empty() == true)
	{
		std::cout << "Mailbox empty" << std::endl << std::endl;
		return;
	}
	std::cout << "From:    " << _mailBox.back().sender << std::endl;
	std::cout << "Message: " << _mailBox.back().text << std::endl << std::endl;
}
