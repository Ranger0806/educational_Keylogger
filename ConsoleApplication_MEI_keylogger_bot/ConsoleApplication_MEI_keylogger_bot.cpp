#include <iostream>
#include <thread>
#include "GUI.h"
#include "Logger.h"
using namespace std;
//
//int main()
//{
//	thread threadLogger(Logger::run);
//	thread threadGUI(GUI::run);
//	threadLogger.join();
//	threadGUI.join();
//}

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	thread threadLogger(Logger::run);
	thread threadGUI(GUI::run);
	threadLogger.join();
	threadGUI.join();
}