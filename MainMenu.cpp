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
	mainMenu[0].setPosition(400, 200);
	//settings stuff
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Settings");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 300);
	//exit stuff
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 400);

	buttonSelected = -1;
}
int MainMenu::runMenu()
{
	sf::RenderWindow Menu(sf::VideoMode(1344, 960), "Main Menu", sf::Style::Default);
	MainMenu mainMenu(Menu.getSize().x, Menu.getSize().y);
	sf::RectangleShape menuBackground;
	menuBackground.setSize(sf::Vector2f(1344, 960));
	sf::Texture menuTexture;
	//menuTexture.loadFromFile("Images/AA GameBackground.png");
	//load texture
	if (menuTexture.loadFromFile("Images/AA GameBackground.png"))
	{
		std::cout << "Menu texture loaded successfully" << std::endl;
		//set texture to sprite
		menuBackground.setTexture(&menuTexture);
	}
	else
	{
		std::cout << "Menu texture failed to load" << std::endl;
	}
	//menuBackground.setTexture(&menuTexture);
	//implement menu option textures once they are made
	while (Menu.isOpen())
	{
		sf::Event event;
		while (Menu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Menu.close();
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mainMenu.moveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					mainMenu.moveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Enter)
				{
					return mainMenu.buttonPressed();
				}
			}
		}
	}
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
			buttonSelected = 2;
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
		if (buttonSelected == 3)
		{
			buttonSelected = 0;
		}
		mainMenu[buttonSelected].setFillColor(sf::Color::Red);
	}
}