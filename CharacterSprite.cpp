#include "CharacterSprite.hpp"

CharacterSprite::CharacterSprite() : rect(sf::Vector2f(5, 50))
{
	rect.setPosition(0, -50);
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

void CharacterSprite::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->rect);
}
