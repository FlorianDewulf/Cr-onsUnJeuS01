#include "CharacterSprite.hpp"

CharacterSprite::CharacterSprite() : rect(sf::Vector2f(5, 50)), _currentCase(NULL)
{
	rect.setPosition(0, -50);
	this->findCase();
}

CharacterSprite::~CharacterSprite()
{
}

void CharacterSprite::move(const sf::Vector2f &coord)
{
	sf::Vector2f tmp = Tool::toWindowCoord(coord.x, coord.y);
	
	tmp.y -= 50;
	this->rect.setPosition(tmp);
}

void CharacterSprite::findCase()
{
	MapCase *currentCase = DataContainer::getInstance()->map->findTile(DataContainer::getInstance()->light.coord);

	this->_currentCase = currentCase;
}

MapCase * CharacterSprite::getCurrentCase() const
{
	return this->_currentCase;
}

void CharacterSprite::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Transform transform;

	if (this->_currentCase) {
		transform.translate(0, -5 * this->_currentCase->depth * RESIZE_TILE_Y);
	}

	target.draw(this->rect, transform);
}
