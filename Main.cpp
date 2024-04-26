//Ryan Calimlim, CPTS 122, SFML Lab Stuff

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "iostream"

#include "Entity.h"
#include "Player.h"
#include "Wall.h"
#include "Andy.h"
#include "VictoryPoint.h"
#include "MainMenu.h"

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
//nvm Hilze Vonck's stuff is like 7 years old from SFML 1.5 or something and lowkey breaks in spots, we are now using a lot of Mustafa Sibai's code
//from his 30 part creating an RPG C++ / SFML series on youtube

int main(void)
{
	RenderWindow Menu(VideoMode(1344, 960), "Main Menu", Style::Default);
	MainMenu mainMenu(Menu.getSize().x, Menu.getSize().y);
	RectangleShape menuBackground;
	menuBackground.setSize(sf::Vector2f(1344, 960));
	Texture menuTexture;
	//load texture
	if (menuTexture.loadFromFile("Images/AA GameRulesBackground.png"))
	{
		std::cout << "Menu texture loaded successfully" << std::endl;
		//set texture to sprite
		menuBackground.setTexture(&menuTexture);
	}
	else
	{
		std::cout << "Menu texture failed to load" << std::endl;
	}

	//making view window for player character
	View playerView(Vector2f(0.0, 0.0), Vector2f(VIEW_LENGTH, VIEW_HEIGHT));

	//initializing textures
	Texture texPlayerB, texPlayerG, texWall, texWallGun, texAndyChaser, texFireball0, texFireball1, texVictoryThing;
	//initializing sprites
	Sprite spriteBoy, spriteWall, spriteWallGun, spriteAndyChaser, spriteFireball0, spriteFireball1, spriteVictoryThing;

	//game menu
	//MainMenu menu((float)VIEW_LENGTH, (float)VIEW_HEIGHT);
	//menu.runMenu();

	//creating entities
	Player player;
	Wall wall_1, wall_2, wall_3, wall_4, wall_5;
	Andy andy_1, andy_2, andy_3, andy_4, andy_5, andy_6, andy_7, andy_8, andy_9, andy_10, andy_11, andy_12, andy_13, andy_14, andy_15, andy_16;
	VictoryPoint exit;

	//initializing entities
	//player
	player.initialize();
	//walls 1-4
	wall_1.initialize();
	wall_2.initialize();
	wall_3.initialize();
	//andy 1-16
	andy_1.initialize(1, 0);
	andy_2.initialize(-1, 0);
	andy_3.initialize(0, 1);
	andy_4.initialize(0, -1);
	andy_5.initialize(2, 0);
	andy_6.initialize(-2, 0);
	andy_7.initialize(0, 2);
	andy_8.initialize(0, -2);
	andy_9.initialize(2, 0);
	andy_10.initialize(-2, 0);
	andy_11.initialize(0, 2);
	andy_12.initialize(0, -2);
	andy_13.initialize(2, 0);
	andy_14.initialize(-2, 0);
	andy_15.initialize(0, 2);
	andy_16.initialize(0, -2);
	//exit location
	exit.initialize();

	//loading textures to entities
	//every single load function below has a test incorporated within to make sure the texture file opened correctly (player, wall, andy, and exit) 
	//load player
	player.load();
	//load walls
	wall_1.load(Vector2f(20, 3), 0);
	wall_2.load(Vector2f(20, 3), 90);
	wall_3.load(Vector2f(20, 3), 90);
	andy_1.load(192.5, 340);
	andy_2.load(1151, 612);
	andy_3.load(1151.5, 348);
	andy_4.load(192.5, 612);
	andy_5.load(672, 174);
	andy_6.load(672, 786);
	andy_7.load(1247, 480);
	andy_8.load(96.25, 480);
	andy_9.load(VIEW_LENGTH / 2, VIEW_HEIGHT);
	andy_10.load(VIEW_LENGTH / 2, 0);
	andy_11.load(0, VIEW_HEIGHT / 2);
	andy_12.load(VIEW_LENGTH, VIEW_HEIGHT / 2);
	andy_13.load(0, VIEW_HEIGHT);
	andy_14.load(VIEW_LENGTH, 0);
	andy_15.load(0, 0);
	andy_16.load(VIEW_LENGTH, VIEW_HEIGHT);
	exit.load();

	//setting border wall positions
	wall_1.setPosition(Vector2f(VIEW_LENGTH / 2, -150));
	wall_2.setPosition(Vector2f(-180, VIEW_HEIGHT));
	wall_3.setPosition(Vector2f(1494, VIEW_HEIGHT));

	//menuBackground.setTexture(&menuTexture);
	//implement menu option textures once they are made
	while (Menu.isOpen())
	{
		Menu.draw(menuBackground);
		Menu.display();
		Event event;
		while (Menu.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				Menu.close();
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.moveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.moveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					//making game window
					RenderWindow gameWindow;
					gameWindow.create(VideoMode(VIEW_LENGTH, VIEW_HEIGHT, 32), "AbscondAndy");
					//gets user input from menu
					int x = mainMenu.buttonPressed();
					//choice 0, play game
					if (x == 0)
					{
						////display rules here------------------------------------------------------------
						//Texture rulesTexture;
						//Sprite rulesMessage;
						//if (rulesTexture.loadFromFile("Images/AA RulesScreen.png"))
						//{
						//	std::cout << "Rules texture loaded successfully" << std::endl;
						//	rulesMessage.setTexture(rulesTexture);
						//	rulesMessage.setScale(1, 1);
						//	rulesMessage.setPosition(Vector2f(-7.8f, 910.0f));
						//	Menu.draw(rulesMessage);
						//	Menu.display();
						//	Clock clock;
						//	Time time = seconds(5.0f);
						//	Time elapsedTime = clock.getElapsedTime();
						//	while (time.asSeconds() > elapsedTime.asSeconds())
						//	{
						//		elapsedTime = clock.getElapsedTime();
						//	}
						//	Menu.close();
						//}
						//else
						//{
						//	std::cout << "Rules texture failed to load" << std::endl;
						//}
						//Menu.close();

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
								case Event::KeyPressed:
								{
									if (event.key.code == Keyboard::Escape)
									{
										gameWindow.close();
									}
								}
								}
							}

							//every collision calculation below has a built in test case to see if there was collisiosn
							//Andy got ya! printed to console for andy collision (restart game in the middle), You got out! printed to console
							//for exit location collision (you also get the good job screen for winning)

							//collision w/ an andy, you lose
							if (player.getSprite().getGlobalBounds().intersects(andy_1.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 1 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_2.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 2 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_3.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 3 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_4.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 4 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_5.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 5 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_6.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 6 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_7.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 7 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_8.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 8 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_9.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 9 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_10.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 10 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_11.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 11 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_12.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy12 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_13.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 13 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_14.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 14 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_15.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 15 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}
							if (player.getSprite().getGlobalBounds().intersects(andy_16.getSprite().getGlobalBounds()))
							{
								std::cout << "Andy 16 got ya!" << std::endl;
								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
							}

							//exit collision, you won
							if (player.getSprite().getGlobalBounds().intersects(exit.getSprite().getGlobalBounds()))
							{
								std::cout << "You got out!" << std::endl;

								player.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));

								Texture victoryTexture;
								Sprite victoryMessage;
								if (victoryTexture.loadFromFile("Images/AA WinningScreen.png"))
								{
									std::cout << "Victory texture loaded successfully" << std::endl;
									victoryMessage.setTexture(victoryTexture);
									victoryMessage.setScale(1, 1);
									victoryMessage.setPosition(Vector2f(-7.8f, 910.0f));
									gameWindow.draw(victoryMessage);
									gameWindow.display();
									Clock clock;
									Time time = seconds(5.0f);
									Time elapsedTime = clock.getElapsedTime();
									while (time.asSeconds() > elapsedTime.asSeconds())
									{
										elapsedTime = clock.getElapsedTime();
									}
									gameWindow.close();
								}
								else
								{
									std::cout << "Victory texture failed to load" << std::endl;
								}
								gameWindow.close();
							}

							//--------------------------------------------- window display stuff, draws and displays the graphics ----------------------------------

							//center view on player's sprite
							playerView.setCenter(player.getPosition());
							//clear window
							gameWindow.clear(Color::Cyan);
							//set window to the player view
							gameWindow.setView(playerView);

							//update player (movement)
							player.update();
							//update Andys
							//innermost andys
							andy_1.updateX();
							andy_2.updateX();
							andy_3.updateY();
							andy_4.updateY();

							//middle circle andys
							andy_5.updateX();
							andy_6.updateX();
							andy_7.updateY();
							andy_8.updateY();

							//outer circle andys
							andy_9.updateX();
							andy_10.updateX();
							andy_11.updateY();
							andy_12.updateY();
							andy_13.updateX();
							andy_14.updateX();
							andy_15.updateY();
							andy_16.updateY();

							//draw entities
							//draw player
							player.draw(gameWindow);
							//draw walls
							wall_1.draw(gameWindow);
							wall_2.draw(gameWindow);
							wall_3.draw(gameWindow);
							//draw andys
							andy_1.draw(gameWindow);
							andy_2.draw(gameWindow);
							andy_3.draw(gameWindow);
							andy_4.draw(gameWindow);
							andy_5.draw(gameWindow);
							andy_6.draw(gameWindow);
							andy_7.draw(gameWindow);
							andy_8.draw(gameWindow);
							andy_9.draw(gameWindow);
							andy_10.draw(gameWindow);
							andy_11.draw(gameWindow);
							andy_12.draw(gameWindow);
							andy_13.draw(gameWindow);
							andy_14.draw(gameWindow);
							andy_15.draw(gameWindow);
							andy_16.draw(gameWindow);
							//draw exit goal
							exit.draw(gameWindow);

							//displays screen
							gameWindow.display();
						}
					}
					if (x == 1)
					{
						Menu.close();
						break;
					}
				}
			}
		}
		Menu.clear();
		mainMenu.draw(Menu);
		Menu.display();
		}
	return 0;
}


