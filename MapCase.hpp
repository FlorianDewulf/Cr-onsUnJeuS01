#pragma once
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "DataContainer.hpp"
#include "GlobalLight.hpp"
#include "Tool.hpp"

class DataContainer;

class MapCase : public sf::Drawable
{
	// METHODS
public:
	MapCase(const short &, const short &, const sf::Texture &);
	~MapCase();

	//sf::Color calcLightColor(const short & posX, const short & posY, const GlobalLight & light) const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//void addShadowTile(sf::RenderTarget &, const sf::Vector2<const short> &, const sf::Vector2f &, sf::VertexArray &, const GlobalLight &, const sf::Transform &) const;

	// GETTER & SETTER
public:
	sf::Sprite getSprite() const;
	void setSprite(const sf::Sprite &);

	// Attributes
public:
	sf::Vector2i humanCoord;
	sf::Vector2f coord;

private:
	sf::Sprite _sprite;
};

