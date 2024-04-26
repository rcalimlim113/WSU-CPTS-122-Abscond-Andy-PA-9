#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "Entity.h"

using namespace::sf;

class Andy : public Entity
{
private:
	int _speed;
public:
	//overwritten virtual functions
	//initializes Andy
	void initialize();
	//loads texture to sprite
	void load();
	//updates position based on player's movement
	void update();
	//draws sprite to game window
	void draw(RenderWindow& gameWindow);
};

