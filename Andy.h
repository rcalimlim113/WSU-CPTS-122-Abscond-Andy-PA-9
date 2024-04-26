#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "Entity.h"

using namespace::sf;

class Andy : public Entity
{
private:
	int _speedX;
	int _speedY;

public:
	//overwritten virtual functions
	//initializes Andy
	void initialize(int speedX, int speedY);
	//loads texture to sprite
	void load(int startX, int startY);
	//updates position based on player's movement
	void updateX();
	void updateY();
	//draws sprite to game window
	void draw(RenderWindow& gameWindow);
};

