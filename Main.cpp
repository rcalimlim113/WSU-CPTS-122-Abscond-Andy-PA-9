//Ryan Calimlim, CPTS 122, SFML Lab Stuff
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"

using namespace::sf;

int main(void)
{
	RenderWindow window;
	window.create(VideoMode(500, 500, 32), "MyGame");

	Texture faceTexture;
	faceTexture.loadFromFile("Images/Untitled.png");

	Sprite faceSprite;
	faceSprite.setTexture(faceTexture);
	faceSprite.setOrigin(sf::Vector2f(150,150));
	faceSprite.setPosition(sf::Vector2f(250, 250));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(faceSprite);
		window.display();
	}




	return 0;
}