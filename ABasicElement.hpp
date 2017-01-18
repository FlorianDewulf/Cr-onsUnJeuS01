#pragma once
#include <SFML/Graphics.hpp>

class ABasicElement
{
public:
	ABasicElement();
	virtual ~ABasicElement();

public:
	virtual bool isClickable() const;
	virtual bool isSelectable() const;
	virtual bool isScrollable() const;
	virtual bool isInputable() const;

public:
	sf::Vector2i	getPosition() const;
	void			setPosition(const sf::Vector2i &);
	sf::Vector2i	getSize() const;
	void			setSize(const sf::Vector2i &);

public:
	ABasicElement					*parent;
	std::vector<ABasicElement *>	children;

protected:
	sf::Vector2i	_position;
	sf::Vector2i	_size;
};

