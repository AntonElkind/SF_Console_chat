#pragma once
#include <string>
#include <winsock2.h>

class NetWriter
{
public:
	NetWriter();
	~NetWriter();

	void write(const std::string& msg);

private:
	int open();
	void sendArray(const char* sendbuf, int len);
	void close();

	SOCKET ConnectSocket;
	bool isConnected;
};