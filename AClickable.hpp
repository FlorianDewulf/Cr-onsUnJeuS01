#pragma once
#include "ABasicElement.hpp"

class AClickable : public ABasicElement
{
public:
	AClickable();
	virtual ~AClickable();

public:
	virtual bool	isClickable() const;
	virtual bool	click(const sf::Event &);
};

