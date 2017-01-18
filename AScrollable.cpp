#include "AScrollable.hpp"



AScrollable::AScrollable()
{
}


AScrollable::~AScrollable()
{
}

bool AScrollable::isScrollable() const
{
	return true;
}

bool AScrollable::scroll(const sf::Event &event)
{
	return true;
}
