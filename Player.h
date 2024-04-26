#pragma once

#include "SFML/Graphics.hpp"

#include "Entity.h"

using namespace::sf;

//DISCLAIMER
//a fair amount of the SFML related code here is from Hilze Vonck's youtube tutorials  

class Player : public Entity
{
private:
	int _speed;

public:
	Player(Sprite sprite, int speed)
	{
		setSprite(sprite), _speed = speed;
	}
	int getSpeed()
	{
		return _speed;
	}
};
