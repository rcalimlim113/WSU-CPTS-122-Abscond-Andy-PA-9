#include "Andy.h"

void Andy::initialize(int speedX, int speedY)
{
	_speedX = speedX, _speedY = speedY;
}

void Andy::load(int startX, int startY)
{
	//load texture
	if (_texture.loadFromFile("Images/AA AndyTexture.jpg"))
	{
		std::cout << "Andy texture loaded successfully" << std::endl;
		//set texture to sprite
		_sprite.setTexture(_texture);
		_sprite.setScale(Vector2f(0.25, 0.25));
		_sprite.setPosition(startX, startY);
		_sprite.setOrigin(Vector2f(536 / 2, 385 / 2));
	}
	else
	{
		std::cout << "Andy texture failed to load" << std::endl;
	}
}

void Andy::updateX()
{
	//stores current position
	Vector2f position = getPosition();

	//moves andy on X axis, direction decided by speedY
	setPosition(position + Vector2f(0.25 * _speedX, 0));
	if (getPosition().x > 1344)
	{
		setPosition(Vector2f(0, getPosition().y));
	}
	if (getPosition().x < 0)
	{
		setPosition(Vector2f(1344, getPosition().y));
	}
}
void Andy::updateY()
{
	//stores current position
	Vector2f position = getPosition();

	//moves andy on Y axis, direction decided by speedY
	setPosition(position + Vector2f(0, 0.25 * _speedY));
	if (getPosition().y > 960)
	{
		setPosition(Vector2f(getPosition().x, 0));
	}
	if (getPosition().y < 0)
	{
		setPosition(Vector2f(getPosition().x, 960));
	}
}

void Andy::draw(RenderWindow& gameWindow)
{
	gameWindow.draw(getSprite());
}