#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GlobalLight.hpp"
#include "IsometricMap.hpp"
#include "DataContainer.hpp"
#include "KeyboardManager.hpp"
#include "Tool.hpp"

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	sf::Texture texture;
	sf::Clock		clock;

	if (!texture.loadFromFile("assets/tiles/sol.jpg")) {
		return EXIT_FAILURE;
	}

	DataContainer *data = DataContainer::getInstance();
	data->init(&window, 15, 15, texture);

	while (window.isOpen())
	{
		sf::Event event;

		data->clock.update(clock);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			data->keyboard->eventStorage(event);
		}

		data->draw();
	}
	return EXIT_SUCCESS;
}