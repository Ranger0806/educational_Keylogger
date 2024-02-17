#include "Runner.h"

bool Runner::exit = true;
bool Runner::exitProgram = false;

void Runner::run()
{
	std::thread threadGUI(GUI::run);
	std::thread threadLogger(Logger::run);
	threadGUI.join();
	threadLogger.join();
}
