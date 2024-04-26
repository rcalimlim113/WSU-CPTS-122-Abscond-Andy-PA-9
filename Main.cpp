//Ryan Calimlim, CPTS 122, SFML Lab Stuff

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "iostream"

#include "Entity.h"
#include "Player.h"
#include "Wall.h"

using namespace::sf;

//this is some view window stuff for SFML that I got from Hilze Vonck's youtube SFML tutorial series
static const float VIEW_HEIGHT = 960;
static const float VIEW_LENGTH = 1344;

void resizeView(const RenderWindow& window, View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_LENGTH * aspectRatio, VIEW_HEIGHT);
}

//DISCLAIMER
//SFML is confusing and a lot of the SFML related code in this project will be from Hilze Vonck's 14 part youtube SFML tutorial, 
//including the bit right above this disclaimer
//nvm Hilze Vonck's stuff is like 7 years old from SFML 1.5 or something and lowkey breaks in spots, I am now using a lot of Mustafa Sibai's code
//from his 30 part creating an RPG C++ / SFML series on youtube

int main(void)
{
	//making game window
	RenderWindow gameWindow;
	gameWindow.create(VideoMode(VIEW_LENGTH, VIEW_HEIGHT, 32), "MyGame");

	//making view window for player character
	View playerView(Vector2f(0.0, 0.0), Vector2f(VIEW_LENGTH, VIEW_HEIGHT));

	//initializing textures
	Texture texPlayerB, texPlayerG, texWall, texWallGun, texAndyChaser, texFireball0, texFireball1, texVictoryThing;
	//initializing sprites
	Sprite spriteBoy, spriteWall, spriteWallGun, spriteAndyChaser, spriteFireball0, spriteFireball1, spriteVictoryThing;

	//creating player & wall
	Player player;
	Wall wall;

	//initializing player & wall
	player.initialize();
	wall.initialize();

	//loading textures to player & wall
	player.load();
	wall.load();

	//--------------------------------------------- game loop ---------------------------------------
	while (gameWindow.isOpen())
	{
		//this is for window events, like closing the game window or resizing it
		Event event;
		while (gameWindow.pollEvent(event))
		{
			switch (event.type)
			{
				//close window event
				case Event::Closed:
				{
					gameWindow.close();
					break;
				}
				//resize window event
				case Event::Resized:
				{
					resizeView(gameWindow, playerView);
					break;
				}
			}
		}

		//collision
		if (player.getSprite().getGlobalBounds().intersects(wall.getSprite().getGlobalBounds()))
		{
			std::cout << "collision 1" << std::endl;
		}

		//--------------------------------------------- window display stuff, draws and displays the graphics ----------------------------------

		//center view on player's sprite
		playerView.setCenter(player.getPosition());
		//clear window
		gameWindow.clear(Color::Black);
		//set window to the player view
		gameWindow.setView(playerView);

		//update player (movement)
		player.update();

		//draw sprites
		player.draw(gameWindow);
		wall.draw(gameWindow);

		//displays screen
		gameWindow.display();
	}
	return 0;
}



