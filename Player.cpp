#include "Player.h"

void Player::initialize()
{
	_speed = 1;
}

void Player::load()
{
	if (_texture.loadFromFile("Images/AA BoyTexture.png"))
	{
		std::cout << "Player texture loaded successfully" << std::endl;
		_sprite.setTexture(_texture);
		_sprite.setTextureRect(IntRect(0, 0, 32, 32));
		_sprite.setScale(Vector2f(3, 3));
	}
	else
	{
		std::cout << "Player texture failed to load" << std::endl;
	}
}

void Player::update()
{
	Vector2f position = getPosition();

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		setPosition(position + Vector2f(0.25 * getSpeed(), 0));
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		setPosition(position + Vector2f(-0.25 * getSpeed(), 0));
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		setPosition(position + Vector2f(0, -0.25 * getSpeed()));
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		setPosition(position + Vector2f(0, 0.25 * getSpeed()));
	}
}

void Player::draw()
{
	
}
