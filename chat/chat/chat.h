#pragma once
#include <unordered_map>
#include "chatMember.h"
#include "netWriter.h"

class Chat
{
public:
	Chat();

	int registration();
	int logIn();
	void logOut();
	int sendMessage(const std::string& to, const std::string& text);
	void run();

private:
	std::unordered_map<std::string, ChatMember> _members;
	std::string _loggedUserEmail;

	void prompt();
	NetWriter logger;
};