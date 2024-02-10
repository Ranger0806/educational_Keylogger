#pragma once
#include "Sender.h"
class MailSender : public Sender
{
private:
	std::string email = "0";
public:
	MailSender(std::string email);
	void send(std::string message) override;
};

