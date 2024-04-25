#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"

using namespace::sf;

//DISCLAIMER
//Basically all of the code in these Animation .h and .cpp files is taken from Hilze Vonck on youtube, he had a 14 episode SFML tutorial that I watched,
//and this entire animation area is basically all his code because SFML is mad confusing

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
	Animation(Texture* texture, Vector2u imageCount, float switchTime);
	~Animation() {};

	void update(int row, float deltaTime);
};

