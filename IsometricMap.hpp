#pragma once

#include <list>
#include <SFML/Graphics.hpp>
#include "MapCase.hpp"
#include "GlobalLight.hpp"

class MapCase;

class IsometricMap
{
public:
	IsometricMap(const short &, const short &, const sf::Texture &);
	~IsometricMap();

	void renderMap(sf::RenderWindow &, const GlobalLight &);

	short getWidth() const;
	void setWidth(const short &);
	short getHeight() const;
	void setHeight(const short &);
	sf::VertexArray &getShadowTile();

private:
	short 	_width;
	short 	_height;
	std::list<MapCase *> _container;
	sf::VertexArray		 _shadow_tile;
};