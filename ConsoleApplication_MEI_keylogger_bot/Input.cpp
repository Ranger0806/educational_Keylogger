#include "Input.h"

Input::Input(float x, float y)
{
	this->x = x;
	this->y = y;
	this->bgTexture = new sf::Texture();
	if (!bgTexture->loadFromFile("assets/inputbg.png")) {
		return;
	}
	this->background = new sf::Sprite(*bgTexture);
	background->setPosition(x, y);
	this->font = new sf::Font();
	if (!font->loadFromFile("assets/arial.ttf")) {
		return;
	}
	this->widgetText = new sf::Text();
	widgetText->setFont(*font);
	widgetText->setCharacterSize(20);
	widgetText->setPosition(x + 2, y + 1);
	this->cursor = new sf::Text("|", *font, 20);
}

void Input::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*background, states);
	target.draw(*widgetText, states);
	target.draw(*cursor, states);
}
