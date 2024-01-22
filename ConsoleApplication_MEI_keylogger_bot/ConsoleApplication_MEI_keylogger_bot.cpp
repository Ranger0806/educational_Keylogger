#include <iostream>
#include <thread>
#include "GUI.h"
#include "Logger.h"

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	/*std::thread threadLogger(Logger::run);*/
	std::thread threadGUI(GUI::run);
	/*threadLogger.join();*/
	threadGUI.join();
}