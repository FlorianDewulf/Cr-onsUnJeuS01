#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

#include "GlobalLight.hpp"
#include "IsometricMap.hpp"
#include "DataContainer.hpp"
#include "KeyboardManager.hpp"
#include "Tool.hpp"

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	sf::Clock		clock;
	DataContainer *data = DataContainer::getInstance();

	srand(NULL);

	data->load_manager->openFile("mymap2");
	data->load_manager->loadMap();
	data->load_manager->closeFile();

	data->init(&window, data->load_manager->getList());

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