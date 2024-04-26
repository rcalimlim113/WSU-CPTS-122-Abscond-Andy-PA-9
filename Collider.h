#pragma once

#include "SFML/Graphics.hpp"

using namespace::sf;

//DISCLAIMER
//a lot of this is from Hilze Vonck's collision video

class Collider
{
private:
	RectangleShape& _body;

public:
	//constructor and destructor
	Collider(RectangleShape& body);
	~Collider();

	//getters for the position and half size of the body in question
	Vector2f getPosition(void)
	{
		return _body.getPosition();
	}
	Vector2f getHalfSize(void)
	{
		return _body.getSize() / 2.0f;
	}

	bool checkCollision(Collider& other, float push);

	void Move(float dx, float dy) 
	{
		_body.move(dx, dy); 
	}

};

