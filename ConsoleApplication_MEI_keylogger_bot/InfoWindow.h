#pragma once
#include <SFML/Graphics.hpp>
class InfoWindow
{
public:
	static void run(sf::RenderWindow& rwindow);
	static void mainWinMSGHandle(sf::Window& window, sf::Window& child);
};

