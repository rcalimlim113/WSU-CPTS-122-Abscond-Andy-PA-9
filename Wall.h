#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

#include "Entity.h"

using namespace::sf;

class Wall : public Entity
{
public:
	void initialize();
	void load();
	void draw();
};