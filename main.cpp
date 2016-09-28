#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GlobalLight.hpp"
#include "IsometricMap.hpp"
#include "DataContainer.hpp"
#include "KeyboardManager.hpp"
#include "Tool.hpp"

// TMP
#include <cstdlib>

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	sf::Texture texture;
	sf::Clock		clock;

	if (!texture.loadFromFile("assets/tiles/sol.jpg")) {
		return EXIT_FAILURE;
	}

	// TMP
	srand(time(NULL));

	DataContainer *data = DataContainer::getInstance();
	data->init(&window, 15, 15, texture);

	while (window.isOpen())
	{
		sf::Event event;

		data->clock.update(clock);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				data->save_manager->saveMap(data->map);
				data->save_manager->closeFile();

				data->load_manager->openFile("save.lol");
				data->load_manager->loadMap();
				data->load_manager->closeFile();

				window.close();
			}

			data->keyboard->eventStorage(event);
		}

		data->draw();
	}
	return EXIT_SUCCESS;
}