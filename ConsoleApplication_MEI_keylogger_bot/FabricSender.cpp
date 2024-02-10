#include "FabricSender.h"

FabricSender::FabricSender()
{
	std::ifstream f;
	f.open("config.txt");
	if (f.is_open()) {
		getline(f, tgId);
		getline(f, email);
	}
}

Sender** FabricSender::createSenders()
{
	Sender** senders = new Sender * [2];
	if (email != "0") {
		senders[0] = new MailSender(email);
	}
	if (tgId != "0") {
		senders[1] = new TgSender(tgId);
	}
	return senders;
}
