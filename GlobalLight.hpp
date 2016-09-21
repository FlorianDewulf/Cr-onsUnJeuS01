#pragma once
#include <SFML/Graphics.hpp>
#include "CharacterSprite.hpp"
#include "DataContainer.hpp"

class DataContainer;

class GlobalLight
{
public:
	GlobalLight();
	~GlobalLight();

	void drawShadow();
	sf::VertexArray &getShadowTile();

private:
	void drawPartialShadow(const sf::Vector2i &, DataContainer *);
	sf::Color calcLightColor(const short &, const short &);

public:
	sf::Vector2f coord;

private:
	sf::VertexArray		 _shadow_tile;
};

