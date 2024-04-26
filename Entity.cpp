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
	//making a vector to store movement data
	Vector2f movement(0.0f, 0.0f);

	//getting movement data from user keypresses
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

	//set new animation texture (animation lowkey broken ngl)
	_body.setTextureRect(_animation.uvRect);
	//move the sprite to the new location, as dictated by movement vector
	_body.move(movement);
}
