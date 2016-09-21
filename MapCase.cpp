#include "MapCase.hpp"
// TMP
#include <cstdlib>
#include <iostream>

unsigned short MapCase::id_count = 1;

MapCase::MapCase(const short & x, const short & y, const sf::Texture &texture) : id(MapCase::id_count++), humanCoord(x, y), coord(x, y), _sprite(texture), depth(0)
{
	sf::Vector2u size = this->_sprite.getTexture()->getSize();
	sf::Vector2f new_position(Tool::toWindowCoord(x, y, true));

	this->_sprite.setRotation(ROTATION_TILE);
	this->_sprite.setScale(sf::Vector2f(100.f / (float)size.x, 100.f / (float)size.y));
	this->_sprite.setPosition(new_position);

	// TMP - waiting loading map
	this->depth = rand() % 11;
}

MapCase::~MapCase()
{
}

void MapCase::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Transform transform;
	transform.scale(1.f, RESIZE_TILE_Y);
	transform.translate(0, - this->depth * 5);

	target.draw(this->_sprite, transform);

	this->addShadowTile(
		target,
		sf::Vector2<const short>(this->coord.x, this->coord.y),
		Tool::toWindowCoord(this->coord.x, this->coord.y, true),
		DataContainer::getInstance()->map->getShadowTile(),
		DataContainer::getInstance()->light,
		transform
	);

	if (this->depth != 0) {
		transform.scale(1, 1);
		this->addDepthTile(
			target,
			Tool::toWindowCoord(this->coord.x, this->coord.y, true),
			DataContainer::getInstance()->map->getShadowTile(),
			transform
		);
	}
}

sf::Sprite MapCase::getSprite() const
{
	return this->_sprite;
}

void MapCase::setSprite(const sf::Sprite &new_sprite)
{
	this->_sprite = new_sprite;
}

sf::Color		MapCase::calcLightColor(const short &posX, const short &posY, const GlobalLight &light) const {
	float			distX = 0.0f;
	float			distY = 0.0f;

	distX = Tool::abs(posX - light.coord.x);
	distY = Tool::abs(posY - light.coord.y);

	return sf::Color(
		static_cast<unsigned char>(std::max(125 - ((distX + distY) * 15), 0.0f)),
		static_cast<unsigned char>(std::max(125 - ((distX + distY) * 15), 0.0f)),
		static_cast<unsigned char>(std::max(125 - ((distX + distY) * 15), 0.0f)),
		static_cast<unsigned char>(std::min((distX + distY) < 5 ? 0 : 255 - (140 - ((distX + distY) * 7)), 255.0f))
	);
}


void		MapCase::addShadowTile(sf::RenderTarget &window, const sf::Vector2<const short> &real_position, const sf::Vector2f &position, sf::VertexArray &shadowTile, const GlobalLight &light, const sf::Transform &transform) const
{
	shadowTile[0].color = this->calcLightColor(real_position.x, real_position.y, light);
	shadowTile[1].color = this->calcLightColor(real_position.x + 1, real_position.y, light);
	shadowTile[2].color = this->calcLightColor(real_position.x + 1, real_position.y + 1, light);
	shadowTile[3].color = this->calcLightColor(real_position.x, real_position.y + 1, light);

	if (shadowTile[0].color.a + shadowTile[1].color.a + shadowTile[2].color.a + shadowTile[2].color.a != 0) {

		shadowTile[0].position = sf::Vector2f(position.x, position.y);
		shadowTile[1].position = sf::Vector2f(position.x + (this->_sprite.getGlobalBounds().width) / 2, position.y + (this->_sprite.getGlobalBounds().height) / 2);
		shadowTile[2].position = sf::Vector2f(position.x, position.y + (this->_sprite.getGlobalBounds().height));
		shadowTile[3].position = sf::Vector2f(position.x - (this->_sprite.getGlobalBounds().width) / 2, position.y + (this->_sprite.getGlobalBounds().height) / 2);

		window.draw(shadowTile, transform);
	}
}

void MapCase::addDepthTile(sf::RenderTarget &window, const sf::Vector2f &position, sf::VertexArray &tile, const sf::Transform &transform) const
{
	tile[0].color = sf::Color::Black;
	tile[1].color = sf::Color::Black;
	tile[2].color = sf::Color::Black;
	tile[3].color = sf::Color::Black;

	tile[0].position = sf::Vector2f(position.x - (this->_sprite.getGlobalBounds().width) / 2, position.y + (this->_sprite.getGlobalBounds().height) / 2);
	tile[1].position = sf::Vector2f(position.x - 1, position.y + (this->_sprite.getGlobalBounds().height));
	tile[2].position = sf::Vector2f(position.x - 1, position.y + (this->_sprite.getGlobalBounds().height) + (this->depth * 5));
	tile[3].position = sf::Vector2f(position.x - (this->_sprite.getGlobalBounds().width) / 2, position.y + (this->_sprite.getGlobalBounds().height / 2) + (this->depth * 5));

	window.draw(tile, transform);

	tile[0].position = sf::Vector2f(position.x + 1, position.y + this->_sprite.getGlobalBounds().height);
	tile[1].position = sf::Vector2f(position.x + (this->_sprite.getGlobalBounds().width) / 2, position.y + (this->_sprite.getGlobalBounds().height / 2));
	tile[2].position = sf::Vector2f(position.x + (this->_sprite.getGlobalBounds().width) / 2, position.y + (this->_sprite.getGlobalBounds().height / 2) + (this->depth * 5));
	tile[3].position = sf::Vector2f(position.x + 1, position.y + this->_sprite.getGlobalBounds().height + (this->depth * 5));

	window.draw(tile, transform);
}
