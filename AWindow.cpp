#include "AWindow.hpp"

AWindow::AWindow(const unsigned char flag, const sf::Vector2f position, const sf::Vector2f size)
	: ABasicElement(FLAG_EVENT::CLOSED_WINDOW | flag), _background(size), _to_close(WINDOW_DEFAULT)
{
	this->_background.setPosition(position);
	this->_background.setFillColor(sf::Color::Red);
}

AWindow::~AWindow()
{
}

bool AWindow::isDeletable()
{
	return this->_to_close == CLOSED_WINDOW;
}
