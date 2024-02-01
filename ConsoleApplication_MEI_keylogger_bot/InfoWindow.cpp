#include "InfoWindow.h"
void InfoWindow::run(sf::RenderWindow& rwindow)
{
	sf::String strAbout(L"Наше приложение разработано на языке программирования C++, при помощи библиотеки SFML. Выбор данной библиотеки был обусловлен ее простотой, а так же реализацией в ней ООП парадигмы, что отлично подходило для нашего проекта. Для создания интерфейса программы были использованы иконки кнопок (скачанные из интернета), кнопки используются для конфигурации самого кейлоггера. Так же в приложении по отдельной кнопке доступна полная обучающая информация по устройству кейлоггеров и методам защиты от них. В конечном итоге приложение компилирует готовый exe файл с параметрами которые вы указали выше. Отдельным пунктом стоит отметить что в приложении указано о том что это ПО является только обучающим и не может распространяться в целях кражи личной информации.\nДля создания проекта был выбранный язык программирования C++, который является одним из самых быстрых и производительных языков.Язык обладает ООП(Обьектно Ориентированное Программирование), что позволяет организовывать болле эффективные решения, которые будут соответствовать последним стандартам написания кода.");
	
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
