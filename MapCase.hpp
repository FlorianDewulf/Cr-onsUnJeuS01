#pragma once
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "DataContainer.hpp"
#include "GlobalLight.hpp"
#include "SaveMapCase.hpp"
#include "Tool.hpp"

class DataContainer;
class MapCase;
struct SaveMapCase;

class MapCase : public sf::Drawable
{
	// METHODS
public:
	//MapCase(const short &, const short &, const sf::Texture &);
	MapCase(SaveMapCase *, const sf::Texture &);
	~MapCase();

	sf::Color		calcLightColor(const short & posX, const short & posY, const GlobalLight & light) const;
	static bool		linkCases(MapCase *, MapCase *);

private:
	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void			addShadowTile(sf::RenderTarget &, const sf::Vector2<const short> &, const sf::Vector2f &, sf::VertexArray &, const GlobalLight &, const sf::Transform &) const;
	void			addDepthTile(sf::RenderTarget &, const sf::Vector2f &, sf::VertexArray &, const sf::Transform &) const;

	// GETTER & SETTER & VALIDATION
public:
	sf::Sprite		getSprite() const;
	void			setSprite(const sf::Sprite &);
	void			setUpCase(MapCase *);
	void			setLeftCase(MapCase *);
	void			setRightCase(MapCase *);
	void			setBottomCase(MapCase *);
	MapCase			*up() const;
	MapCase			*left() const;
	MapCase			*right() const;
	MapCase			*bottom() const;
	bool			isFullyLinked() const;

	// STATIC Attributes
public:
	static unsigned short	id_count;

	// Attributes
public:
	const unsigned short	id;
	sf::Vector2i			humanCoord;
	sf::Vector2f			coord;
	char					depth;
	bool					can_collide;

private:
	sf::Sprite				_sprite;
	MapCase					*_up_case;
	MapCase					*_left_case;
	MapCase					*_right_case;
	MapCase					*_bottom_case;
};

