#pragma once

#include <list>
#include <SFML/Graphics.hpp>
#include "MapCase.hpp"
#include "GlobalLight.hpp"
#include "Tool.hpp"
#include "DataContainer.hpp"

class MapCase;
class DataContainer;

class IsometricMap
{
public:
	IsometricMap(const short &, const short &, const sf::Texture &);
	~IsometricMap();

	void					renderMap(sf::RenderWindow &, const GlobalLight &);
	MapCase					*findTile(const sf::Vector2f &);
	MapCase					*findHumanTile(const sf::Vector2i &);

	short					getWidth() const;
	void					setWidth(const short &);
	short					getHeight() const;
	void					setHeight(const short &);
	sf::VertexArray			&getShadowTile();
	std::list<MapCase *>	getCaseList() const;

private:
	short					_width;
	short					_height;
	std::list<MapCase *>	_container;
	sf::VertexArray			_shadow_tile;
};