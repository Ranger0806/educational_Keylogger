#pragma once
#include "Sender.h"
#include "tgbot"
using namespace std;
class TgSender : public Sender
{
private:
	TgBot::Bot bot("6374688261:AAEHPkpT06dTrBu07_muKx3TXjvcSymM9vM");
public:
	void send();
};

