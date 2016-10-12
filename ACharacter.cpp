#include "ACharacter.hpp"
#include "DataContainer.hpp"

ACharacter::ACharacter() : _currentCase(NULL), _currentScale(1.0f, 1.0f), _position(0, 0)
{
	this->_texture_character.loadFromFile("assets/orientation.png");

	sf::Vector2u size_texture = this->_texture_character.getSize();
	if ((size_texture.x / 3) / (float)(SIZE_TILE_X) > 1.0f || (size_texture.y / 3) / (float)(SIZE_TILE_Y) > 1.0f) {
		this->_currentScale.x = std::min((float)(SIZE_TILE_X) / (size_texture.x / 3), (float)(SIZE_TILE_Y) / (size_texture.y / 3));
		this->_currentScale.y = this->_currentScale.x;
	}

	this->_character_sprite.setPosition(sf::Vector2f(-(size_texture.x / 3 * this->_currentScale.x / 2), -(size_texture.y / 3 * this->_currentScale.y) + (size_texture.y / 3 * 0.1 * this->_currentScale.y)));
	this->_character_sprite.setTexture(this->_texture_character);
	this->_character_sprite.setTextureRect(sf::IntRect(size_texture.x / 3 * 2, size_texture.y / 3 * 2, size_texture.x / 3, size_texture.y / 3));
	this->_character_sprite.setScale(this->_currentScale);
	this->findCase();
}


ACharacter::~ACharacter()
{
}

void ACharacter::findCase()
{
	MapCase *currentCase = DataContainer::getInstance()->map->findTile(this->_position);

	this->_currentCase = currentCase;
}

MapCase * ACharacter::getCurrentCase() const
{
	return this->_currentCase;
}

void ACharacter::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Transform transform;

	if (this->_currentCase) {
		transform.translate(0, -DEPTH_SIZE * this->_currentCase->depth * RESIZE_TILE_Y);
	}

	target.draw(this->_character_sprite, transform);
}

void ACharacter::move(const sf::Vector2f &coord)
{
	sf::Vector2u size_texture = this->_texture_character.getSize();
	sf::Vector2f tmp = Tool::toWindowCoord(coord.x, coord.y);
	sf::Vector2f default_position = sf::Vector2f((size_texture.x / 3 * this->_currentScale.x / 2), (size_texture.y / 3 * this->_currentScale.y) - (size_texture.y / 3 * 0.1 * this->_currentScale.y));

	this->_character_sprite.setPosition(tmp - default_position);
	this->_position.x = coord.x;
	this->_position.y = coord.y;
}