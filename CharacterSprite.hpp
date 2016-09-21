#pragma once
#include <SFML/Graphics.hpp>
#include "DataContainer.hpp"
#include "MapCase.hpp"
#include "Tool.hpp"

class DataContainer;
class MapCase;

class CharacterSprite : public sf::Drawable
{
public:
	CharacterSprite();
	~CharacterSprite();

	void move(const sf::Vector2f &);
	void findCase();
	MapCase *getCurrentCase() const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape rect;
	MapCase *_currentCase;
};

