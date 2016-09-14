#include "IsometricMap.hpp"

IsometricMap::IsometricMap(const short &base_width, const short &base_height, const sf::Texture &texture)
	: _width(base_width), _height(base_height), _shadow_tile(sf::Quads, 4)
{
	for (unsigned short y = 0; y < base_height; ++y) {
		for (unsigned short x = 0; x < base_width; ++x) {
			this->_container.push_back(new MapCase(x, y, texture));
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
		}
	}
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
