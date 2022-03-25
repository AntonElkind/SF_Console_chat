#pragma once
#include <string>
#include <vector>
#include "user.h"

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
	std::vector<Message> _mailBox;
};

