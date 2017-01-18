#include "AClickable.hpp"

AClickable::AClickable()
{
}

AClickable::~AClickable()
{
}

bool AClickable::isClickable() const
{
	return true;
}

bool AClickable::click(const sf::Event &event)
{
	sf::Vector2i click_position(event.mouseButton.x, event.mouseButton.y);
	
	if (click_position.x >= this->_position.x && click_position.x <= this->_position.x + this->_size.x
		&& click_position.y >= this->_position.y && click_position.y <= this->_position.y + this->_size.y) {
		return true;
	} else {
		return false;
	}
}