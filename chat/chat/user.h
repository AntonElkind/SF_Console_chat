#pragma once
#include <string>
#include "sha1.h"

class User
{
public:
	User();

	void setName(const std::string& name);
	void setEmail(const std::string& email);
	void setPassword(const std::string& password);
	void setOnline(bool onlineState);

	const std::string& getName();
	const std::string& getEmail();
	bool checkPassword(const std::string& password);
	bool isOnline();

private:
	std::string _name;
	std::string _email;
	uint _passwordHash[SHA1_HASH_LENGTH_UINTS];
	bool _online;
};

