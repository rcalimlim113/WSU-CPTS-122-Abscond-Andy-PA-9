#pragma once

#include "SFML/Graphics.hpp"

using namespace::sf;

//DISCLAIMER
//Basically all of the code in these Animation .h and .cpp files is taken from Hilze Vonck's animation tutorial

class Animation
{
private:
	Vector2u _imageCount;
	Vector2u _currentImage;
	float _totalTime;
	float _switchTime;
public:
	IntRect uvRect;
public:
	//constructor and destructor
	Animation(Texture* texture, Vector2u imageCount, float switchTime);
	~Animation() {};

	//updates sprite for the animation
	void update(int row, float deltaTime);
};

