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
	_mailBox.add(msg);
}

void ChatMember::printAll()
{
	for (int i = 0; i < _mailBox.getLength(); ++i)
	{
		std::cout << "From:    " << _mailBox[i].sender << std::endl;
		std::cout << "Message: " << _mailBox[i].text << std::endl << std::endl;
	}
}

void ChatMember::printLast()
{
	std::cout << "From:    " << _mailBox[_mailBox.getLength() - 1].sender << std::endl;
	std::cout << "Message: " << _mailBox[_mailBox.getLength() - 1].text << std::endl << std::endl;
}
