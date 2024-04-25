#include "Entity.h"

Entity::Entity(Texture* texture, Vector2u imageCount, float switchTime, float speed): _animation(texture, imageCount, switchTime)
{
	_speed = speed, _row = 0;

	_body.setSize(Vector2f(100, 100));
	_body.setOrigin(_body.getSize() / 2.0f);
	_body.setTexture(texture);
	_body.setPosition(Vector2f(50, 50));
}

void Entity::update(float deltaTime)
{
	Vector2f movement(0.0f, 0.0f);

	if (Keyboard::isKeyPressed(Keyboard::Key::A))
	{
		movement.x -= _speed*deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D))
	{
		movement.x += _speed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::W))
	{
		movement.y -= _speed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S))
	{
		movement.y += _speed * deltaTime;
	}

	_body.setTextureRect(_animation.uvRect);
	_body.move(movement);
}

void Entity::draw(RenderWindow& window)
{
	window.draw(_body);
}
