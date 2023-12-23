#include "TgSender.h"

void TgSender::send()
{
	bot.getApi().sendMessage(Logger::simbols, "Hi!");
}
