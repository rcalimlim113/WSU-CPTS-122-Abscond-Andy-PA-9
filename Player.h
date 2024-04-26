#pragma once

#include "SFML/Graphics.hpp"

#include "Animation.h"
#include "Collider.h"

using namespace::sf;

//DISCLAIMER
//a fair amount of the SFML related code here is from Hilze Vonck's youtube tutorials  

class Player
{
private:
	RectangleShape _body;
	Animation _animation;
	unsigned int _row;
	float _speed;

public:
	//constructor and destructor
	Player(Texture* texture, Vector2u imageCount, float switchTime, float speed);
	~Player() {};

	//updates sprite position based on keyboard inputs
	void update(float deltaTime);

	//draws player sprite to window
	void draw(RenderWindow& window)
	{
		window.draw(_body);
	}

	//returns player's position
	Vector2f getPosition()
	{
		return _body.getPosition();
	}
	//collision function
	Collider getCollider()
	{
		return Collider(_body);
	}

};
