#include <iostream>
#include <memory>
#include "chat.h"


int main()
{
	std::cout << "Console chat. Block 1 final project" << std::endl;

	std::unique_ptr<Chat> pChat(new Chat);
	pChat->run();

	return 0;
}