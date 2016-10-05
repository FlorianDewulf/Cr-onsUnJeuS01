#pragma once
#include <SFML/Graphics.hpp>
#include "Enum.hpp"

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

public:
	std::map<TextureConstants, sf::Texture *>		texture_pool;
};

