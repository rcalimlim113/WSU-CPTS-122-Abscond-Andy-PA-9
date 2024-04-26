#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("Fonts/GingerCat.ttf"))
	{
		std::cout << "No font found";
	}
	//play stuff
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition((1344/2)-80, 960/3);
	//exit stuff
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Exit");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition((1344/2)-80, 400);

	buttonSelected = -1;
}
void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; ++i)
	{
		window.draw(mainMenu[i]);
	}
}
void MainMenu::moveUp()
{
	if (buttonSelected - 1 >= 0)
	{
		mainMenu[buttonSelected].setFillColor(sf::Color::White);
		buttonSelected--;
		if (buttonSelected == -1)
		{
			buttonSelected = 1;
		}
		mainMenu[buttonSelected].setFillColor(sf::Color::Red);
	}
}
void MainMenu::moveDown()
{
	if (buttonSelected + 1 <= Max_main_menu)
	{
		mainMenu[buttonSelected].setFillColor(sf::Color::White);
		buttonSelected++;
		if (buttonSelected == 2)
		{
			buttonSelected = 0;
		}
		mainMenu[buttonSelected].setFillColor(sf::Color::Red);
	}
}