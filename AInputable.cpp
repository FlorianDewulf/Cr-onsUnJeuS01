#include "AInputable.hpp"



AInputable::AInputable()
{
}


AInputable::~AInputable()
{
}

bool AInputable::isInputable() const
{
	return true;
}

bool AInputable::input(const sf::Event &event)
{
	return true;
}
