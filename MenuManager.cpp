#include "MenuManager.hpp"

MenuManager::MenuManager()
{
}

MenuManager::~MenuManager()
{
}

void MenuManager::processEvents(InputStorage &input_store)
{
	std::queue<sf::Event>	&key_list		= input_store.getKeyEvents();
	std::queue<sf::Event>	&click_list		= input_store.getClickEvents();
	sf::Event				*scroll_event	= input_store.getScrollEvent();

	for (std::list<ABasicElement *>::iterator it = this->_menu_elements.begin(); it != this->_menu_elements.end();) {
		if ((*it)->isClickable()) {
			sf::Event e = click_list.front();

			// For the Mouse
			if (static_cast<AClickable *>(*it)->click(e)) {
				this->_already_process.push_back((*it));
				it = this->_menu_elements.erase(it);

				click_list.pop();
			}
		} else if ((*it)->isInputable()) {
			sf::Event e = key_list.front();

			// For the Input
			if (static_cast<AInputable *>(*it)->input(e)) {
				this->_already_process.push_back((*it));
				it = this->_menu_elements.erase(it);

				key_list.pop();
			}
		} else if ((*it)->isScrollable() && scroll_event) {
			// For the Scroll
			if (static_cast<AScrollable *>(*it)->scroll(*scroll_event)) {
				this->_already_process.push_back((*it));
				it = this->_menu_elements.erase(it);

				scroll_event = NULL;
			}
		} else {
			++it;
		}
	}
}

bool MenuManager::resetWindows()
{
	for (std::list<ABasicElement *>::iterator it = this->_already_process.begin(); it != this->_already_process.end();) {
		this->_menu_elements.push_back((*it));
		it = this->_already_process.erase(it);
	}
	return false;
}
