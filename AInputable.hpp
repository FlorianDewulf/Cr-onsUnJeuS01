#pragma once
#include "ABasicElement.hpp"

class AInputable : public ABasicElement
{
public:
	AInputable();
	virtual ~AInputable();

public:
	virtual bool	isInputable() const;
	virtual bool	input(const sf::Event &);
};

