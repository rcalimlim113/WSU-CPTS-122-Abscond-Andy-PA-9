#include "Andy.h"

void Andy::initialize()
{
	_speed = 1;
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
		_sprite.setPosition(50, -350);
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

	////moves sprite in direction of keypress, at speed decided by _speed
	//if (Keyboard::isKeyPressed(Keyboard::D))
	//{
	//	setPosition(position + Vector2f(0.25 * _speed, 0));
	//}
	//if (Keyboard::isKeyPressed(Keyboard::A))
	//{
	//	setPosition(position + Vector2f(-0.25 * _speed, 0));
	//}
	//if (Keyboard::isKeyPressed(Keyboard::W))
	//{
	//	setPosition(position + Vector2f(0, -0.25 * _speed));
	//}
	//if (Keyboard::isKeyPressed(Keyboard::S))
	//{
	//	setPosition(position + Vector2f(0, 0.25 * _speed));
	//}
}

void Andy::draw(RenderWindow& gameWindow)
{
	gameWindow.draw(getSprite());
}