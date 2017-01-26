#include "CoreController.hpp"
#include "MenuWindowDialog.hpp"

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

	/* test */
	srand(time(NULL));

	data->texture_manager.loadSet("set_one");

	data->load_manager->openFile("mymap");
	data->load_manager->loadMap();
	data->load_manager->closeFile();

	data->init(data->load_manager->getList());


	/* test */


	std::vector<std::string> tutu;
	tutu.push_back("Ceci est un test");
	tutu.push_back("Ceci marche");
	tutu.push_back("Ca va disparaitre");

	MenuWindowDialog toto(data->npcs.front(), data->main_character, tutu);

	this->menu_manager._menu_elements.push_back(&toto);

	/* test */

	while (data->window.isOpen())
	{
		sf::Event event;

		data->clock.update(clock);
		this->input_store.cleanScroll();
		std::cout << "precoucou 1" << std::endl;
		this->menu_manager.resetWindows();
		std::cout << "precoucou 2" << std::endl;
		while (data->window.pollEvent(event))
		{
			if (!this->input_store.addEvent(event)) {
				data->window.close();
				return;
			}
		}

		data->keyboard->eventStorage(this->input_store.getKeyEventsForKeyboard());
		std::cout << "coucou 1" << std::endl;
		this->menu_manager.processEvents(this->input_store);
		std::cout << "coucou 2" << std::endl;
		this->menu_manager.clearWindows();
		std::cout << "coucou 3" << std::endl;

		data->update();
		data->draw();
		std::cout << "coucou 4" << std::endl;
		this->menu_manager.draw();
		std::cout << "coucou 5" << std::endl;
		data->window.display();
	}
}