#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class Input : public sf::Drawable
{
private:
	string text;
	sf::Sprite* background = nullptr;
	sf::Texture* bgTexture = nullptr;
	sf::Font* font = nullptr;
	sf::Text* widgetText = nullptr;
	sf::Text* cursor = nullptr;
	float x;
	float y;
public:
	Input(float x, float y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void changeText(char simbol);
};

