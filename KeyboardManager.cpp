#include "KeyboardManager.hpp"

KeyboardManager::KeyboardManager()
{
	this->input_mapping[sf::Keyboard::Z] = FORWARD;
	this->input_mapping[sf::Keyboard::Up] = FORWARD;
	this->input_mapping[sf::Keyboard::S] = BACKWARD;
	this->input_mapping[sf::Keyboard::Down] = BACKWARD;
	this->input_mapping[sf::Keyboard::Q] = LEFT;
	this->input_mapping[sf::Keyboard::Left] = LEFT;
	this->input_mapping[sf::Keyboard::D] = RIGHT;
	this->input_mapping[sf::Keyboard::Right] = RIGHT;
	this->input_mapping[sf::Keyboard::Escape] = ESCAPE;

	this->process_method_map[FORWARD] = &KeyboardManager::moveForward;
	this->process_method_map[BACKWARD] = &KeyboardManager::moveBackward;
	this->process_method_map[LEFT] = &KeyboardManager::moveLeft;
	this->process_method_map[RIGHT] = &KeyboardManager::moveRight;
	this->process_method_map[ESCAPE] = &KeyboardManager::closeWindow;
}

KeyboardManager::~KeyboardManager()
{
}

void KeyboardManager::eventStorage(const sf::Event &event)
{
	std::list<KeyConstants>::iterator ptr;

	if (event.type == sf::Event::KeyPressed) {
		for (std::map<sf::Keyboard::Key, KeyConstants>::iterator it = this->input_mapping.begin(); it != this->input_mapping.end(); ++it) {
			if (event.key.code == it->first && (ptr = find(this->actions.begin(), this->actions.end(), it->second)) == this->actions.end()) {
				this->actions.push_back(it->second);
				return;
			}
		}
	} else if (event.type == sf::Event::KeyReleased) {
		for (std::map<sf::Keyboard::Key, KeyConstants>::iterator it = this->input_mapping.begin(); it != this->input_mapping.end(); ++it) {
			if (event.key.code == it->first && (ptr = find(this->actions.begin(), this->actions.end(), it->second)) != this->actions.end()) {
				this->actions.erase(ptr);
				return;
			}
		}
	}
}

void KeyboardManager::eventInterpreter()
{
	for (std::list<KeyConstants>::iterator it = this->actions.begin(); it != this->actions.end(); ++it) {
		if (this->process_method_map.find(*it) != this->process_method_map.end()) {
			(*this.*process_method_map[*it])(NULL);
		}
	}
}

/**
 * Private
 * Method for the method pointer
 */

void KeyboardManager::moveForward(void *) const
{
	DataContainer::getInstance()->light.coord.y -= 0.01f;
	DataContainer::getInstance()->main_character.move(DataContainer::getInstance()->light.coord);
}

void KeyboardManager::moveLeft(void *) const
{
	DataContainer::getInstance()->light.coord.x -= 0.01f;
	DataContainer::getInstance()->main_character.move(DataContainer::getInstance()->light.coord);
}

void KeyboardManager::moveBackward(void *) const
{
	DataContainer::getInstance()->light.coord.y += 0.01f;
	DataContainer::getInstance()->main_character.move(DataContainer::getInstance()->light.coord);
}

void KeyboardManager::moveRight(void *) const
{
	DataContainer::getInstance()->light.coord.x += 0.01f;
	DataContainer::getInstance()->main_character.move(DataContainer::getInstance()->light.coord);
}

void KeyboardManager::closeWindow(void *) const
{
	DataContainer::getInstance()->window->close();
}
