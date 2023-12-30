#pragma once
#include <fstream>
#include <string>
#include "Sender.h"
#include "TgSender.h"
#include "MailSender.h"

class FabricSender
{
private:
	std::string tgId = "0";
	std::string email = "0";
public:
	FabricSender();
	Sender** createSenders();
};

