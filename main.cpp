#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "GlobalLight.hpp"
#include "IsometricMap.hpp"
#include "DataContainer.hpp"
#include "KeyboardManager.hpp"

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	sf::Texture texture;
	KeyboardManager keyboard;

	if (!texture.loadFromFile("assets/tiles/sol.jpg")) {
		return EXIT_FAILURE;
	}

	DataContainer *data = DataContainer::getInstance();
	data->init(&window, 10, 10, texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			keyboard.eventStorage(event);
		}

		window.clear();
		keyboard.eventInterpreter();
		data->updateView();
		data->map->renderMap(window, data->light);
		window.draw(data->main_character);
		window.display();
	}
	return EXIT_SUCCESS;
}