#include "TgSender.h"

TgSender::TgSender(std::string userId)
{
	this->userId = userId;
}

void TgSender::send(std::string message)
{
	if (message != "") {
		std::ofstream a("tgtest.txt");
		a << userId << std::endl << message << std::endl;
		TgBot::Bot bot("");
		bot.getApi().sendMessage(userId, message);
	}
}
