#include "TextureManager.hpp"

TextureManager::TextureManager()
{
	int nb_texture;

	for (nb_texture = 0; texture_constants[nb_texture] != NO_TEXTURE; ++nb_texture) {
		this->texture_pool[texture_constants[nb_texture]] = new sf::Texture();
		this->texture_pool[texture_constants[nb_texture]]->loadFromFile("assets/tiles/image_" + std::to_string(nb_texture) + ".png");
	}
}


TextureManager::~TextureManager()
{
}
