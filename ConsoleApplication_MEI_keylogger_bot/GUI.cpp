#include "GUI.h"

void GUI::run()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::Texture unchecked;
    if (!unchecked.loadFromFile("assets/unchecked.png")) {
        return;
    }
    sf::Sprite unSprite(unchecked);
    unSprite.setPosition(50, 50);
    unSprite.setScale(0.5, 0.5);

    sf::Texture checked;
    if (!checked.loadFromFile("assets/checked.png")) {
        return;
    }
    sf::Sprite chSprite(checked);
    chSprite.setPosition(50, 100);
    chSprite.setScale(0.5, 0.5);

    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf"))
    {
        return;
    }

    sf::Text text1;
    text1.setFont(font);
    text1.setString("Hello world");
    text1.setCharacterSize(24);
    text1.setFillColor(sf::Color::Red);
    text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text1.setPosition(50, 60);

    sf::Text text2;
    text2.setFont(font);
    text2.setString("Hi");
    text2.setCharacterSize(24);
    text2.setFillColor(sf::Color::Red);
    text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text2.setPosition(50, 120);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(unSprite);
        window.draw(chSprite);
        window.draw(text1);
        window.draw(text2);
        window.display();
    }
}
