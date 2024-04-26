#include "VictoryPoint.h"

void VictoryPoint::initialize()
{

}

void VictoryPoint::load()
{
	//load texture
	if (_texture.loadFromFile("Images/AA TempVictoryTexture.png"))
	{
		std::cout << "Victory Point texture loaded successfully" << std::endl;
		//set texture to sprite
		_sprite.setTexture(_texture);
		_sprite.setScale(Vector2f(0.25, 0.25));
		_sprite.setPosition(500, -200);
	}
	else
	{
		std::cout << "Victory Point texture failed to load" << std::endl;
	}
}

void VictoryPoint::draw(RenderWindow& gameWindow)
{
	gameWindow.draw(getSprite());
}