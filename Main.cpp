//Ryan Calimlim, CPTS 122, SFML Lab Stuff

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "iostream"

#include "Entity.h"
#include "Player.h"
#include "Wall.h"
#include "Enemy.h"
#include "Fireball.h"
#include "Animation.h"

using namespace::sf;

//this is some view window stuff for SFML that I got from Hilze Vonck's youtube SFML tutorial series
static const float VIEW_HEIGHT = 1080;
static const float VIEW_LENGTH = 1920;

void resizeView(const RenderWindow& window, View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_LENGTH * aspectRatio, VIEW_HEIGHT);
}

//DISCLAIMER
//SFML is confusing and a lot of the SFML related code in this project will be from Hilze Vonck's youtube SFML tutorial, including the bit right above this disclaimer

int main(void)
{
	//making game window
	RenderWindow gameWindow;
	gameWindow.create(VideoMode(1920, 1080, 32), "MyGame");

	//making view window on player character
	View playerView(Vector2f(0.0, 0.0), Vector2f(VIEW_LENGTH, VIEW_HEIGHT));

	//initializing textures
	Texture texPlayerB, texPlayerG, texWall, texWallGun, texAndyChaser, texFireball0, texFireball1, texVictoryThing;
	texPlayerB.loadFromFile("Images/CPTS 122 PA 9 BoyTexture.png");

	//initializing sprites
	Sprite spriteBoy, spriteGirl, spriteWall, spriteWallGun, spriteAndyChaser, spriteFireball0, spriteFireball1, spriteVictoryThing;

	//this is some SFML stuff that I dont get but Hilze Vonck uses it in the youtube tutorials and it's necessary for movement and animations and stuff
	float deltaTime = 0.0f;
	Clock clock;

	//testing stuff
	RectangleShape originMark(Vector2f(20,20));
	originMark.setFillColor(Color::Blue);
	originMark.setOrigin(10, 10);
	originMark.setPosition(960, 500);

	//player entity
	Entity player(&texPlayerB, Vector2u(2, 2), 0.3f, 150.0f);


	//game loop
	while (gameWindow.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		//this is for window events, like closing the game window or resizing it
		Event event;
		while (gameWindow.pollEvent(event))
		{
			switch (event.type)
			{
				case Event::Closed:
				{
					gameWindow.close();
					break;
				}
				case Event::Resized:
				{
					resizeView(gameWindow, playerView);
					break;
				}
			}
		}


		//window display stuff, draws and displays the graphics
		player.update(deltaTime);
		playerView.setCenter(player.getPosition());

		gameWindow.clear(Color(255,0,255));
		gameWindow.setView(playerView);
		player.draw(gameWindow);
		gameWindow.draw(originMark);
		gameWindow.display();

	}
	return 0;
}