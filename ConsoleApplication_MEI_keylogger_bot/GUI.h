#pragma once
#include "Input.h"
#include <map>
#include <SFML/Graphics.hpp>
#include "InfoWindow.h"
#include <thread>
#include <fstream>
#include <regex>
#include "Runner.h"
class GUI
{
private:
	static std::string filename;
public:
	static void run();
};

