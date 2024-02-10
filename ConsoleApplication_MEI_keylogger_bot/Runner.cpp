#include "Runner.h"

int Runner::exit = 0;

void Runner::run()
{
	exit = 0;
	std::thread threadGUI(GUI::run);
	threadGUI.join();
	std::thread threadLogger(Logger::run);
	threadLogger.join();
}
