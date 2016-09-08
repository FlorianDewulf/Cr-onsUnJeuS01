#pragma once
#include <SFML/Graphics.hpp>
#include "GlobalLight.hpp"
#include "IsometricMap.hpp"
#include "CharacterSprite.hpp"

class GlobalLight;
class IsometricMap;

class DataContainer
{
public:
	static DataContainer	*getInstance();

	void init(sf::RenderWindow * const, const short &, const short &, const sf::Texture &);
	void updateView();

public:
	sf::RenderWindow		*window;
	GlobalLight				light;
	IsometricMap			*map;
	CharacterSprite			main_character;

private:
	DataContainer();
	~DataContainer();
	DataContainer &operator=(const DataContainer &);
	DataContainer(const DataContainer &);

	static DataContainer	*_instance;
};