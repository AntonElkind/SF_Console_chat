#pragma once
#include <string>

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
	const std::string& getPassword();
	bool isOnline();

private:
	std::string _name;
	std::string _email;
	std::string _password;
	bool _online;
};

