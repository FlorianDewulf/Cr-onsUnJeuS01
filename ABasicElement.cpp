#include "ABasicElement.hpp"

ABasicElement::ABasicElement()
{
}


ABasicElement::~ABasicElement()
{
	for (std::vector<ABasicElement *>::iterator it = this->children.begin(); it != this->children.end(); ++it) {
		delete (*it);
	}
}

bool ABasicElement::isClickable() const
{
	return false;
}

bool ABasicElement::isSelectable() const
{
	return false;
}

bool ABasicElement::isScrollable() const
{
	return false;
}

bool ABasicElement::isInputable() const
{
	return false;
}

sf::Vector2i ABasicElement::getPosition() const
{
	return this->_position;
}

void ABasicElement::setPosition(const sf::Vector2i &position)
{
	this->_position.x = position.x;
	this->_position.y = position.y;
}

sf::Vector2i ABasicElement::getSize() const
{
	return this->_size;
}

void ABasicElement::setSize(const sf::Vector2i &size)
{
	this->_size.x = size.x;
	this->_size.y = size.y;
}
