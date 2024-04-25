#pragma once

#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"

#include "Animation.h"

using namespace::sf;

using std::string;

//DISCLAIMER
//a fair amount of the SFML related code here is from Hilze Vonck's youtube tutorials  

class Entity
{
private:
	RectangleShape _body;
	Animation _animation;
	unsigned int _row;
	float _speed;

public:
	Entity(Texture* texture, Vector2u imageCount, float switchTime, float speed);
	~Entity() {};

	void update(float deltaTime);
	void draw(RenderWindow& window);

	Vector2f getPosition()
	{
		return _body.getPosition();
	}

};


