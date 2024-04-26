#include "Wall.h"

void Wall::initialize()
{

}

void Wall::load(Vector2f scale, float rotation)
{
	//load texture
	if (_texture.loadFromFile("Images/AA WallTexture.png"))
	{
		std::cout << "Wall texture loaded successfully" << std::endl;
		//set texture to sprite
		_sprite.setTexture(_texture);
		_sprite.setScale(scale);
		_sprite.setOrigin(Vector2f(114 / 2, 52 / 2));
		_sprite.setRotation(rotation);
	}
	else
	{
		std::cout << "Wall texture failed to load" << std::endl;
	}
}

void Wall::draw(RenderWindow& gameWindow)
{
	gameWindow.draw(getSprite());
}
