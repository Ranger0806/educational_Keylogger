#pragma once
#include <tgbot/tgbot.h>
#include "Sender.h"
using namespace std;

class TgSender : public Sender
{
private:
	string userId = "1332422290";
	//read from file
public:
	void send(string message) override;
};

