#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Input : public sf::Drawable
{
private:
	std::string text;
	sf::Sprite* background = nullptr;
	sf::Texture* bgTexture = nullptr;
	sf::Font* font = nullptr;
	sf::Text* widgetText = nullptr;
	sf::Text* cursor = nullptr;
	sf::Clock* clock = new sf::Clock();
	float x;
	float y;
	bool active = false;
	float positionTextX;
	float positionTextY;
public:
	Input(float x, float y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void changeText(char simbol);
	void dActive();
	void setActive();
	sf::FloatRect getGlobalBound() const;
};

