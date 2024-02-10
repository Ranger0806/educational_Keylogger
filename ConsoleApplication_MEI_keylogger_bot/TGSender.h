#pragma once
#include <tgbot/tgbot.h>
#include "Sender.h"

class TgSender : public Sender
{
private:
	std::string userId = "0";
public:
	TgSender(std::string userId);
	void send(std::string message) override;
};

