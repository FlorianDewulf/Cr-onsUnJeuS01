#include "IsometricMap.hpp"
#include <iostream>

IsometricMap::IsometricMap(const short &base_width, const short &base_height, const sf::Texture &texture)
	: _width(base_width), _height(base_height), _shadow_tile(sf::Quads, 4)
{
	std::list<MapCase *> link_container;

	for (unsigned short y = 0; y < base_height; ++y) {
		for (unsigned short x = 0; x < base_width; ++x) {
			MapCase *tmp = new MapCase(x, y, texture);

			this->_container.push_back(tmp);
			link_container.push_back(tmp);
		}
	}

	for (std::list<MapCase *>::iterator initial_case = link_container.begin(); initial_case != link_container.end(); ++initial_case) {

		if ((*initial_case)->isFullyLinked()) {
			initial_case = link_container.erase(initial_case);
		}

		for (std::list<MapCase *>::iterator comp_case = link_container.begin(); comp_case != link_container.end(); ++comp_case) {
			if ((*initial_case)->id == (*comp_case)->id) {
				continue;
			}

			MapCase::linkCases((*initial_case), (*comp_case));

			if ((*comp_case)->isFullyLinked()) {
				comp_case = link_container.erase(comp_case);
				--comp_case;
			}
			if ((*initial_case)->isFullyLinked()) {
				initial_case = link_container.erase(initial_case);
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
	for (std::list<MapCase *>::iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		if (Tool::isInBoundDataCoord((*it)->humanCoord, DataContainer::getInstance()->getMinCoordBound(), DataContainer::getInstance()->getMaxCoordBound())) {
			window.draw((**it));

			if (DataContainer::getInstance()->main_character->getCurrentCase()->id == (*it)->id) {
				DataContainer::getInstance()->window->draw(*DataContainer::getInstance()->main_character);
			}
		}
	}
}

MapCase *IsometricMap::findTile(const sf::Vector2f &position)
{
	for (std::list<MapCase *>::iterator it = this->_container.begin(); it != this->_container.end(); ++it) {
		if ((int)(*it)->coord.x == (int)position.x && (int)(*it)->coord.y == (int)position.y) {
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

short IsometricMap::getWidth() const
{
	return this->_width;
}

void IsometricMap::setWidth(const short &new_width)
{
	this->_width = new_width;
}

short IsometricMap::getHeight() const
{
	return this->_height;
}

void IsometricMap::setHeight(const short &new_height)
{
	this->_width = new_height;
}

sf::VertexArray & IsometricMap::getShadowTile()
{
	return this->_shadow_tile;
}

std::list<MapCase*> IsometricMap::getCaseList() const
{
	return this->_container;
}
