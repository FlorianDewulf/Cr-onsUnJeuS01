#pragma once
#include <SFML/Graphics.hpp>
#include "CharacterSprite.hpp"
#include "GameClock.hpp"
#include "GlobalLight.hpp"
#include "IsometricMap.hpp"
#include "KeyboardManager.hpp"
#include "SaveManager.hpp"
#include "LoadManager.hpp"

class CharacterSprite;
class GameClock;
class GlobalLight;
class IsometricMap;
class KeyboardManager;
class SaveManager;
class LoadManager;

class DataContainer
{
public:
	static DataContainer	*getInstance();

	void			init(sf::RenderWindow * const, const short &, const short &, const sf::Texture &);
	void			updateView();
	void			draw();

	sf::Vector2i	getMinCoordBound() const;
	sf::Vector2i	getMaxCoordBound() const;

public:
	sf::RenderWindow		*window;
	GlobalLight				light;
	IsometricMap			*map;
	CharacterSprite			*main_character;
	KeyboardManager			*keyboard;
	GameClock				clock;
	SaveManager				*save_manager;
	LoadManager				*load_manager;

private:
	DataContainer();
	~DataContainer();
	DataContainer(const DataContainer &);
	DataContainer &operator=(const DataContainer &);

private:
	sf::Vector2i			_minCoordBounds;
	sf::Vector2i			_maxCoordBounds;

	static DataContainer	*_instance;
};