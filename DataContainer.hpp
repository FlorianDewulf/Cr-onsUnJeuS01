#pragma once
#include <SFML/Graphics.hpp>
#include "CharacterSprite.hpp"
#include "GameClock.hpp"
#include "GlobalLight.hpp"
#include "IsometricMap.hpp"
#include "KeyboardManager.hpp"
#include "LoadManager.hpp"
#include "MusicManager.hpp"
#include "SoundManager.hpp"
#include "TextureManager.hpp"

class CharacterSprite;
class GameClock;
class GlobalLight;
class IsometricMap;
class KeyboardManager;
class LoadManager;
class MusicManager;
class SoundManager;
class TextureManager;

class DataContainer
{
public:
	static DataContainer	*getInstance();

	void			init(sf::RenderWindow * const, std::list<MapCase*> *);
	void			update();
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
	LoadManager				*load_manager;
	TextureManager			texture_manager;
	SoundManager			sound_manager;
	MusicManager			music_manager;

private:
	DataContainer();
	~DataContainer();
	DataContainer(const DataContainer &);
	DataContainer &operator=(const DataContainer &);

	void			_updateView();

private:
	sf::Vector2i			_minCoordBounds;
	sf::Vector2i			_maxCoordBounds;

	static DataContainer	*_instance;
};