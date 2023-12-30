#pragma once
#ifndef SENDER_H
#define SENDER_H
#include <string>

class Sender
{
public:
	virtual void send(std::string message);
};

#endif

