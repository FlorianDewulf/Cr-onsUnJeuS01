#include "MenuTextButton.hpp"



MenuTextButton::MenuTextButton()
{
}


MenuTextButton::~MenuTextButton()
{
}

bool MenuTextButton::click(const sf::Event &event)
{
	bool is_clicked = AClickable::click(event);

	if (is_clicked) {
		// todo : process ? Call function pointer ?
		return true;
	}
	return is_clicked;
}
