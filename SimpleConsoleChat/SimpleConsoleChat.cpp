#include <iostream>
#include "Chat.h"

int main()
{
    setlocale(LC_ALL, "Rus");
	Chat<std::string> chat;

	chat.start();
	while (chat.isChatWork()) {
		chat.showLoginMenu();

		while (chat.getCurrentUser()) {
			chat.showUserMenu();
		}
	}
}


