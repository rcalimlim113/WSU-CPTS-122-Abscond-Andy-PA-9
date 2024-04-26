#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "Entity.h"
#include "Andy.h"

using namespace::sf;

class Player : public Entity
{
private:
	int _speed;
	bool win;
	bool lose;
public:
	//overwritten virtual functions
	//initializes player
	void initialize();
	//loads texture to sprite
	void load();
	//updates position based on movement
	void update();
	//draws sprite to game window
	void draw(RenderWindow& gameWindow);
};
