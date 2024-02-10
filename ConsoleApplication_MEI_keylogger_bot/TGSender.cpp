#include "TgSender.h"

TgSender::TgSender(std::string userId)
{
	this->userId = userId;
}

void TgSender::send(std::string message)
{
	TgBot::Bot bot("6374688261:AAEHPkpT06dTrBu07_muKx3TXjvcSymM9vM");
	bot.getApi().sendMessage(userId, message);
}
