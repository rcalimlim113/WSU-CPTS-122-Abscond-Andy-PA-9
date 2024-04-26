#pragma once

#include "SFML/Graphics.hpp"

#include "Animation.h"

using namespace::sf;

class Entity
{
private:
	Sprite _sprite;
public:
	//constructors and destructor
	Entity() {};
	Entity(Sprite sprite)
	{
		_sprite = sprite;
	}
	~Entity() {};
	//getters and setters
	Sprite getSprite()
	{
		return _sprite;
	}
	void setSprite(Sprite sprite)
	{
		_sprite = sprite;
	}
	Vector2f getPosition()
	{
		return _sprite.getPosition();
	}
	void setPosition(Vector2f position)
	{
		_sprite.setPosition(position);
	}

};


