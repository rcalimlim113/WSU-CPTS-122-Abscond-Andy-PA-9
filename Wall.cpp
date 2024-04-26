#include "Wall.h"

Wall::Wall(Texture* texture, Vector2f size, Vector2f position)
{
	_body.setSize(size);
	_body.setOrigin(size / 2.0f);
	_body.setTexture(texture);
	_body.setPosition(position);
}