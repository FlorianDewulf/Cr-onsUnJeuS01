#pragma once
#include <SFML/Graphics.hpp>
#include "CharacterSprite.hpp"
#include "GameClock.hpp"
#include "GlobalLight.hpp"
#include "IsometricMap.hpp"
#include "KeyboardManager.hpp"

class CharacterSprite;
class GameClock;
class GlobalLight;
class IsometricMap;
class KeyboardManager;

class DataContainer
{
public:
	static DataContainer	*getInstance();

	void init(sf::RenderWindow * const, const short &, const short &, const sf::Texture &);
	void updateView();
	void draw();

	sf::Vector2i	getMinCoordBound() const;
	sf::Vector2i	getMaxCoordBound() const;

public:
	sf::RenderWindow		*window;
	GlobalLight				light;
	IsometricMap			*map;
	CharacterSprite			*main_character;
	KeyboardManager			*keyboard;
	GameClock				clock;

private:
	DataContainer();
	~DataContainer();
	DataContainer &operator=(const DataContainer &);
	DataContainer(const DataContainer &);

private:
	sf::Vector2i	_minCoordBounds;
	sf::Vector2i	_maxCoordBounds;

	static DataContainer	*_instance;
};