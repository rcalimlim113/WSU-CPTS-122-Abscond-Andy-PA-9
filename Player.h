#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "Entity.h"

using namespace::sf;

//DISCLAIMER
//a fair amount of the SFML related code here is from Hilze Vonck's youtube tutorials  

class Player : public Entity
{
private:
	int _speed;

public:
	//overwritten virtual functions
	//initializes player
	void initialize();
	//loads texture to sprite
	void load();
	//updates position based on movement
	void update();
	//draws sprite to game window
	void draw(RenderWindow* gameWindow);
};
