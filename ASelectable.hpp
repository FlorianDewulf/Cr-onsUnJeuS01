#pragma once
#include "ABasicElement.hpp"

class ASelectable : public ABasicElement
{
public:
	ASelectable();
	virtual ~ASelectable();

public:
	virtual bool	isSelectable() const;
	virtual void	select(const sf::Event &);
};

