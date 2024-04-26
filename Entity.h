#pragma once

#include "SFML/Graphics.hpp"

#include "Animation.h"

using namespace::sf;

class Entity
{
protected:
	Texture _texture;
	Sprite _sprite;
public:
	//constructors and destructor
	//Entity() {};
	//~Entity() {};

	virtual void initialize() = 0;
	virtual void load() = 0;
	virtual void update() {};
	virtual void draw() = 0;

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
	void setTexture(Texture texture)
	{
		_texture = texture;
	}

};


