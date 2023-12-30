#pragma once
//#include <tgbot/tgbot.h>
#include "Sender.h"

class TgSender : public Sender
{
private:
	std::string userId = "1332422290";
	//read from file
public:
	void send(std::string message) override;
};

