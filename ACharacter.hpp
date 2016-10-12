#pragma once
#include <SFML/Graphics.hpp>
#include "Tool.hpp"

class DataContainer;
class MapCase;

class ACharacter : public sf::Drawable
{
public:
	ACharacter();
	virtual ~ACharacter();
	virtual void				findCase();
	virtual MapCase				*getCurrentCase() const;
	virtual void				move(const sf::Vector2f & coord);

	sf::Vector2f		_position;
protected:
	virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;
	MapCase				*_currentCase;
	sf::Sprite			_character_sprite;
	sf::Texture			_texture_character;
	sf::Vector2f		_currentScale;
};