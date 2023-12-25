#pragma once
#include "Sender.h"
#include <tgbot/tgbot.h>
using namespace std;

class TgSender : public Sender
{
private:
	TgBot::Bot* bot;
	string userId = "1332422290";
	// read from file
public:
	TgSender();
	void send(string message) override;
};

