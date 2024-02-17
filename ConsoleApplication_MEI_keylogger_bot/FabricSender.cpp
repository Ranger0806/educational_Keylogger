#include "FabricSender.h"

FabricSender::FabricSender()
{
	std::ifstream f;
	f.open("config.txt");
	if (f.is_open()) {
		getline(f, email);
		getline(f, tgId);
	}
}

Sender** FabricSender::createSenders()
{
	Sender** senders = new Sender * [2];
	if (email != "0") {
		senders[0] = new MailSender(email);
	}
	else {
		senders[0] = nullptr;
	}
	if (tgId != "0") {
		senders[1] = new TgSender(tgId);
	}
	else {
		senders[1] = nullptr;
	}
	return senders;
}
