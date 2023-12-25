#pragma once
#include "Sender.h"
class MailSender : public Sender
{
public:
	void send(string message) override;
};

