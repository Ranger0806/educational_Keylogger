#include "TgSender.h"

TgSender::TgSender() {
	bot = new TgBot::Bot("6374688261:AAEHPkpT06dTrBu07_muKx3TXjvcSymM9vM");
}

void TgSender::send(string message)
{
	bot->getApi().sendMessage(userId, message);
}
