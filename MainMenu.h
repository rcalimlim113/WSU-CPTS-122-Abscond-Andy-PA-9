#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define Max_main_menu 3
class MainMenu
{
public:
	MainMenu(float width, float height);
	int runMenu();
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	int buttonPressed() {
		return buttonSelected;
	}
	~MainMenu();
private:
	int buttonSelected;
	
	sf::Font font;
	sf::Text mainMenu[Max_main_menu];
};

