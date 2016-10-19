#include "IsometricMap.hpp"
#include <iostream>

IsometricMap::IsometricMap(std::list<MapCase *> *list)
	: _shadow_tile(sf::Quads, 4), _container(*list)
{
	for (std::list<MapCase *>::iterator initial_case = list->begin(); initial_case != list->end(); ++initial_case) {

		if ((*initial_case)->isFullyLinked()) {
			initial_case = list->erase(initial_case);
		}

		for (std::list<MapCase *>::iterator comp_case = list->begin(); comp_case != list->end(); ++comp_case) {
			if ((*initial_case)->id == (*comp_case)->id) {
				continue;
			}

			MapCase::linkCases((*initial_case), (*comp_case));

			if ((*comp_case)->isFullyLinked()) {
				comp_case = list->erase(comp_case);
				--comp_case;
			}
			if ((*initial_case)->isFullyLinked()) {
				initial_case = list->erase(initial_case);
				--initial_case;
				break;
			}
		}
	}
}

IsometricMap::~IsometricMap()
{
	for (std::list<MapCase *>::iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		delete (*it);
	}
}

void IsometricMap::renderMap(sf::RenderWindow &window, const GlobalLight &light)
{
	std::list<NPC *> npcs = DataContainer::getInstance()->npcs;
	std::list<Item *> items = DataContainer::getInstance()->items;
	bool already_displayed_main_character = false;
	std::list<IObject *> sprite_to_display;

	for (std::list<MapCase *>::iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		if (Tool::isInBoundDataCoord((*it)->humanCoord, DataContainer::getInstance()->getMinCoordBound(), DataContainer::getInstance()->getMaxCoordBound())) {
			window.draw((**it));

			if (!already_displayed_main_character && DataContainer::getInstance()->main_character->getCurrentCase() &&
					DataContainer::getInstance()->main_character->getCurrentCase()->id == (*it)->id) {
				sprite_to_display.push_back(DataContainer::getInstance()->main_character);
				already_displayed_main_character = true;
			}

			for (std::list<NPC *>::iterator npc = npcs.begin(); npc != npcs.end(); ++npc) {
				// assume un pnj / case, careful
				if ((*npc)->getCurrentCase() && (*npc)->getCurrentCase()->id == (*it)->id) {
					sprite_to_display.push_back(*npc);
					npcs.erase(npc);
					break;
				}
			}

			for (std::list<Item *>::iterator item = items.begin(); item != items.end(); ++item) {
				// assume un obj / case, careful
				if ((*item)->getCurrentCase() && (*item)->getCurrentCase()->id == (*it)->id) {
					sprite_to_display.push_back(*item);
					items.erase(item);
					break;
				}
			}

			// Spéciale dédicasse à Sacrefeu <3
			sprite_to_display.sort([](const IObject *character_one, const IObject *character_two) {
				return character_one->_position.x + character_one->_position.y < character_two->_position.x + character_two->_position.y;
			});
			for (std::list<IObject *>::iterator obj = sprite_to_display.begin(); obj != sprite_to_display.end(); ++obj) {
				DataContainer::getInstance()->window->draw(**obj);
			}
		}
	}
}

MapCase *IsometricMap::findTile(const sf::Vector2f &position)
{
	for (std::list<MapCase *>::iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		if (floor((*it)->coord.x) == floor(position.x) && floor((*it)->coord.y) == floor(position.y)) {
			return *it;
		}
	}

	return NULL;
}

MapCase * IsometricMap::findHumanTile(const sf::Vector2i &position)
{
	for (std::list<MapCase *>::iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		if ((*it)->humanCoord.x == position.x && (*it)->humanCoord.y == position.y) {
			return *it;
		}
	}

	return NULL;
}

sf::VertexArray & IsometricMap::getShadowTile()
{
	return this->_shadow_tile;
}

std::list<MapCase*> IsometricMap::getCaseList() const
{
	return this->_container;
}

MapCase * IsometricMap::getRandomCase() const
{
	unsigned int random_number = rand() % this->_container.size();
	unsigned int i = 0;

	for (std::list<MapCase *>::const_iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		if (i == random_number) {
			return *it;
		}
		++i;
	}

	return nullptr;
}
