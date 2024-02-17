#pragma once
#include <iostream>
#include <thread>
#include "GUI.h"
#include "Logger.h"

class Runner {
public:
	static bool exitProgram;
	static void run();
	static bool exit;
};