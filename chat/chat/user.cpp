#include "user.h"

User::User() : _online(false)
{
	_name.clear();
	_email.clear();
	_password.clear();
}

void User::setName(const std::string& name)
{
	_name = name;
}

void User::setEmail(const std::string& email)
{
	_email = email;
}

void User::setPassword(const std::string& password)
{
	_password = password;
}

void User::setOnline(bool onlineState)
{
	_online = onlineState;
}

const std::string& User::getName()
{
	return _name;
}

const std::string& User::getEmail()
{
	return _email;
}

const std::string& User::getPassword()
{
	return _password;
}

bool User::isOnline()
{
	return _online;
}
