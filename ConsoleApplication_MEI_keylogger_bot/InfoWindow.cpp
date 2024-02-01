#include "InfoWindow.h"
void InfoWindow::run(sf::RenderWindow& rwindow)
{
	sf::String strAbout(L"���� ���������� ����������� �� ����� ���������������� C++, ��� ������ ���������� SFML. ����� ������ ���������� ��� ���������� �� ���������, � ��� �� ����������� � ��� ��� ���������, ��� ������� ��������� ��� ������ �������. ��� �������� ���������� ��������� ���� ������������ ������ ������ (��������� �� ���������), ������ ������������ ��� ������������ ������ ����������. ��� �� � ���������� �� ��������� ������ �������� ������ ��������� ���������� �� ���������� ����������� � ������� ������ �� ���. � �������� ����� ���������� ����������� ������� exe ���� � ����������� ������� �� ������� ����. ��������� ������� ����� �������� ��� � ���������� ������� � ��� ��� ��� �� �������� ������ ��������� � �� ����� ���������������� � ����� ����� ������ ����������.\n��� �������� ������� ��� ��������� ���� ���������������� C++, ������� �������� ����� �� ����� ������� � ���������������� ������.���� �������� ���(�������� ��������������� ����������������), ��� ��������� �������������� ����� ����������� �������, ������� ����� ��������������� ��������� ���������� ��������� ����.");
	
	sf::Font font;
	if (!font.loadFromFile("assets/arial.ttf"))
	{
		return;
	}

	sf::Text aboutText;
	aboutText.setString(strAbout);
	aboutText.setFillColor(sf::Color::Black);
	aboutText.setFont(font);
	aboutText.setCharacterSize(14);

	const int WIDTH_WINDOW = 600;
	const int HEIGHT_WINDOW = 600;
	bool checkedStatusEmail = false;
	bool checkedStatusTG = false;
	sf::RenderWindow window(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "KeyLogger", sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::LostFocus)
			{
				if (rwindow.hasFocus()) {
					window.requestFocus();
					/*rwindow.setActive(true);
					window.setActive(false);*/
				}
			}
		}
		mainWinMSGHandle(rwindow, window);
		window.clear(sf::Color::White);
		window.draw(aboutText);
		window.display();
	}
}

void InfoWindow::mainWinMSGHandle(sf::Window& window, sf::Window& child)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			child.close();
			window.close();
		}
		if (event.type == sf::Event::GainedFocus)
		{
			child.requestFocus();
		}
	}
}
