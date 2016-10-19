#include "AObject.hpp"
#include "DataContainer.hpp"

IObject::IObject(const std::string &filename) : _currentCase(NULL), _currentScale(1.0f, 1.0f), _position(0, 0)
{
	this->_texture_character.loadFromFile(filename);
}

IObject::~IObject()
{
}

MapCase * IObject::getCurrentCase() const
{
	return this->_currentCase;
}

void IObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Transform transform;

	if (this->_currentCase) {
		transform.translate(0, -DEPTH_SIZE * this->_currentCase->depth * RESIZE_TILE_Y);
	}

	target.draw(this->_character_sprite, transform);
}

void IObject::findCase()
{
	MapCase *currentCase = DataContainer::getInstance()->map->findTile(this->_position);

	this->_currentCase = currentCase;
}