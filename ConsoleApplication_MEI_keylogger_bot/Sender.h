#pragma once
#include "Logger.h"
using namespace std;
class Sender : public Logger
{
public:
	virtual void send();
};

