#include "user.h"

User::User() : _online(false)
{
	_name.clear();
	_email.clear();
	memset(_passwordHash, 0, SHA1_HASH_LENGTH_BYTES);
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
	Block tmpHash = sha1(password.c_str(), password.length());
	memcpy(_passwordHash, tmpHash, SHA1_HASH_LENGTH_BYTES);
	delete[] tmpHash;
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

bool User::checkPassword(const std::string& password)
{
	Block tmpHash = sha1(password.c_str(), password.length());
	bool compare = static_cast<bool>(memcmp(tmpHash, _passwordHash, SHA1_HASH_LENGTH_BYTES));
	delete[] tmpHash;
	return !compare;
}

bool User::isOnline()
{
	return _online;
}
