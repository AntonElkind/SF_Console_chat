#pragma once
#include <string>
#include "user.h"
#include "container.h"

struct Message
{
	std::string sender;
	std::string text;
};

class ChatMember : public User
{
public:
	ChatMember();
	ChatMember(int id);

	void setID(int id);
	int getID();

	void putMessage(const std::string& sender, const std::string& text);
	void printAll();
	void printLast();

private:
	int _id;
	Container<Message> _mailBox;
};

