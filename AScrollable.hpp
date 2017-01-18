#pragma once
#include "ABasicElement.hpp"

class AScrollable : public ABasicElement
{
public:
	AScrollable();
	virtual ~AScrollable();

public:
	virtual bool	isScrollable() const;
	virtual bool	scroll(const sf::Event &);
};

