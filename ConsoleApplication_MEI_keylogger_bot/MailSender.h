#pragma once
#include "Sender.h"
class MailSender : public Sender
{
public:
	void send(std::string message) override;
};

