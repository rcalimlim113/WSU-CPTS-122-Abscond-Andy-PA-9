#pragma once

#include "SFML/Graphics.hpp"

#include "Entity.h"

using namespace::sf;

class Wall : public Entity
{
private:

public:
	Wall(Sprite sprite)
	{
		setSprite(sprite);
	}
};