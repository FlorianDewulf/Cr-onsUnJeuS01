#pragma once
#include <SFML/Graphics.hpp>
#include "Tool.hpp"

class CharacterSprite : public sf::Drawable
{
public:
	CharacterSprite();
	~CharacterSprite();

	void move(const sf::Vector2f &);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape rect;
};

