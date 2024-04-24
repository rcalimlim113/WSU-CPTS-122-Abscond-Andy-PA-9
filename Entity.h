#pragma once

#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"

using namespace::sf;

using std::string;

class Entity
{
private:
	int _xCoord;
	int _yCoord;
	int _xWidth;
	int _yWidth;
	string _name;
	Sprite _entitySprite;

public:
	//getters
	int getXCoord(void)
	{
		return _xCoord;
	}
	int getYCoord(void)
	{
		return _yCoord;
	}
	int getXWidth(void)
	{
		return _xWidth;
	}
	int getYWidth(void)
	{
		return _yWidth;
	}
	string getName(void)
	{
		return _name;
	}
	Sprite getSprite(void)
	{
		return _entitySprite;
	}

	//setters
	void setXCoord(int xCoord)
	{
		_xCoord = xCoord;
	}
	void setYCoord(int yCoord)
	{
		_yCoord = yCoord;
	}
	void setXWidth(int xWidth)
	{
		_xWidth = xWidth;
	}
	void setYWidth(int yWidth)
	{
		_yWidth = yWidth;
	}
	void setName(string name)
	{
		_name = name;
	}
	void setSprite(Sprite entitySprite)
	{
		_entitySprite = entitySprite;
	}
};


