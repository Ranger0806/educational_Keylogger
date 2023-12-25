#pragma once
#include <fstream>
#include <string>
#include "Sender.h"
#include "TgSender.h"
#include "MailSender.h"
using namespace std;

class FabricSender
{
private:
	string tgId = "0";
	string email = "0";
public:
	FabricSender();
	Sender** createSenders();
};

