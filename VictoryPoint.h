#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "Entity.h"

using namespace::sf;

class VictoryPoint : public Entity
{
public:
	//overwritten virtual functions
	//initializes victory point
	void initialize();
	//loads texture to sprite
	void load();
	//draws sprite to game window
	void draw(RenderWindow& gameWindow);
};
