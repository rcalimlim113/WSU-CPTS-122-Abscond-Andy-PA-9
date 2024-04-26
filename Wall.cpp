#include "Wall.h"

void Wall::initialize()
{

}

void Wall::load()
{
	if (_texture.loadFromFile("Images/AA WallTexture.png"))
	{
		std::cout << "Wall texture loaded successfully" << std::endl;
		_sprite.setTexture(_texture);
		_sprite.setScale(Vector2f(10, 2));
	}
	else
	{
		std::cout << "Wall texture failed to load" << std::endl;
	}
}

void Wall::draw()
{

}
