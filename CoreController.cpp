#include "CoreController.hpp"

CoreController::CoreController()
{
}

CoreController::~CoreController()
{
}

void CoreController::process()
{
	sf::Clock		clock;
	DataContainer	*data = DataContainer::getInstance();

	srand(time(NULL));

	data->texture_manager.loadSet("set_one");

	data->load_manager->openFile("mymap");
	data->load_manager->loadMap();
	data->load_manager->closeFile();

	data->init(data->load_manager->getList());

	while (data->window.isOpen())
	{
		sf::Event event;

		data->clock.update(clock);
		this->input_store.cleanScroll();
		while (data->window.pollEvent(event))
		{
			if (!this->input_store.addEvent(event)) {
				data->window.close();
				return;
			}
		}

		data->keyboard->eventStorage(this->input_store.getKeyEventsForKeyboard());
		this->menu_manager.processEvents(this->input_store);

		data->update();
		data->draw();
	}
}