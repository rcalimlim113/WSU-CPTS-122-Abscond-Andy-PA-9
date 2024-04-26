#include "Andy.h"

void Andy::initialize()
{
	_speed = 1.5;
}

void Andy::load()
{
	//load texture
	if (_texture.loadFromFile("Images/AA AndyTexture.jpg"))
	{
		std::cout << "Andy texture loaded successfully" << std::endl;
		//set texture to sprite
		_sprite.setTexture(_texture);
		_sprite.setScale(Vector2f(0.25, 0.25));
		_sprite.setPosition(0, 0);
	}
	else
	{
		std::cout << "Andy texture failed to load" << std::endl;
	}
}

void Andy::update()
{
	//stores current position
	Vector2f position = getPosition();

	//moves andy to the right
	setPosition(position + Vector2f(0.25 * _speed, 0));

	if (getPosition().x > 1344)
	{
		setPosition(Vector2f(0, getPosition().y));
	}


}

void Andy::draw(RenderWindow& gameWindow)
{
	gameWindow.draw(getSprite());
}