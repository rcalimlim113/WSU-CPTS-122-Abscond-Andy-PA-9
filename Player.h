#pragma once

#include "SFML/Graphics.hpp"
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
	void initialize();
	void load();
	void update();
	void draw();

	int getSpeed()
	{
		return _speed;
	}
};
