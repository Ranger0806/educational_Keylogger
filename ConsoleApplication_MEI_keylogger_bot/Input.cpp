#include "Input.h"

Input::Input(float x, float y)
{
	this->x = x;
	this->y = y;
	this->positionTextX = x + 20;
	this->positionTextY = y + 10;
	this->bgTexture = new sf::Texture();
	if (!bgTexture->loadFromFile("assets/inputbg.png")) {
		return;
	}
	this->background = new sf::Sprite(*bgTexture);
	background->setPosition(x, y);
	background->setScale(0.5, 0.5);
	this->font = new sf::Font();
	if (!font->loadFromFile("assets/arial.ttf")) {
		return;
	}
	this->widgetText = new sf::Text();
	widgetText->setFont(*font);
	widgetText->setCharacterSize(20);
	widgetText->setPosition(positionTextX, positionTextY);
	widgetText->setFillColor(sf::Color::Black);
	this->cursor = new sf::Text("|", *font, 20);
	cursor->setFillColor(sf::Color::Black);
}

void Input::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*background, states);
	widgetText->setString(text);
	target.draw(*widgetText, states);
	if (active && int(clock->getElapsedTime().asSeconds()) % 2 == 0) {
		cursor->setPosition(positionTextX + widgetText->getLocalBounds().width, positionTextY);
		target.draw(*cursor, states);
	}
}

void Input::changeText(std::string simbol)
{
	text += simbol;
}

void Input::dActive()
{
	active = false;
}

void Input::setActive()
{
	active = true;
}

bool Input::isActive()
{
	return active;
}

void Input::remLast()
{
	if (text.size() > 0) {
		text = text.substr(0, text.size() - 1);
	}
}

std::string Input::getText()
{
	return text;
}

sf::FloatRect Input::getGlobalBound() const
{
	return background->getGlobalBounds();
}
