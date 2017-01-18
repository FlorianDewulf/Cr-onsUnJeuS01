#pragma once
#include "AButton.hpp"

class MenuTextButton : public AButton
{
public:
	MenuTextButton();
	virtual ~MenuTextButton();
	virtual bool click(const sf::Event &);
};