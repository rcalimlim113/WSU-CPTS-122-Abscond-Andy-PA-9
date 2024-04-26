#pragma once

#include "SFML/Graphics.hpp"
#include "Collider.h"

using namespace::sf;

class Wall
{
private:
	RectangleShape _body;

public:
	//constructor & destructor
	Wall(Texture* texture, Vector2f size, Vector2f position);
	~Wall() {};

	void draw(RenderWindow& window)
	{
		window.draw(_body);
	}
	Collider getCollider()
	{
		return Collider(_body);
	}
};

