#pragma once
#include "container.h"
#include "chatMember.h"

class Chat
{
public:
	Chat();

	int registration();
	int logIn();
	void logOut();
	int sendMessage(const std::string& to, const std::string& text);

private:
	Container<ChatMember> _members;
	int loggedUserIndex;

	int nameToID(const std::string& name);

};