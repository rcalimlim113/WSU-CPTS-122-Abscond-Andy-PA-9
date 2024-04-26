#include "Player.h"

static const float VIEW_HEIGHT = 960;
static const float VIEW_LENGTH = 1344;

void Player::initialize()
{
	_speed = 1;
	win = false;
	lose = false;
}

void Player::load()
{
	//load texture
	if (_texture.loadFromFile("Images/AA BoyTexture.png"))
	{
		std::cout << "Player texture loaded successfully" << std::endl;
		//set texture to sprite
		_sprite.setTexture(_texture);
		_sprite.setTextureRect(IntRect(0, 0, 32, 32));
		_sprite.setScale(Vector2f(3, 3));
		_sprite.setPosition(Vector2f(VIEW_LENGTH / 2.0f, VIEW_HEIGHT / 2.0f));
		_sprite.setOrigin(Vector2f(16, 16));
	}
	else
	{
		std::cout << "Player texture failed to load" << std::endl;
	}
}

void Player::update()
{
	//stores current position
	Vector2f position = getPosition();

	//moves sprite in direction of keypress, at speed decided by _speed
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		setPosition(position + Vector2f(0.25 * _speed, 0));
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		setPosition(position + Vector2f(-0.25 * _speed, 0));
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		setPosition(position + Vector2f(0, -0.25 * _speed));
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		setPosition(position + Vector2f(0, 0.25 * _speed));
	}
}

void Player::draw(RenderWindow& gameWindow)
{
	gameWindow.draw(getSprite());
}
