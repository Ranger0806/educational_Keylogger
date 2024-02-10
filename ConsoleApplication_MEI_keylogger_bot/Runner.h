#pragma once
#include <iostream>
#include <thread>
#include "GUI.h"
#include "Logger.h"

class Runner {
public:
	static void run();
	static int exit;
};