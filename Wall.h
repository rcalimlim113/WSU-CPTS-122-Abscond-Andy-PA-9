#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "Entity.h"

using namespace::sf;

class Wall : public Entity
{
public:
	//overwritten virtual functions
	//initializes wall
	void initialize();
	//loads texture to sprite
	void load(Vector2f scale, float rotation);
	//draws sprite to game window
	void draw(RenderWindow& gameWindow);
};