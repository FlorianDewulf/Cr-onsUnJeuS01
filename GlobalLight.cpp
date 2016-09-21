#include "GlobalLight.hpp"
#include <iostream>

GlobalLight::GlobalLight() : coord(0, 0), _shadow_tile(sf::Quads, 4)
{
}


GlobalLight::~GlobalLight()
{
}

void GlobalLight::drawShadow()
{
	DataContainer *data = DataContainer::getInstance();

	this->drawPartialShadow(data->getMinCoordBound(), data);
	this->drawPartialShadow(sf::Vector2i(data->getMaxCoordBound().x, data->getMinCoordBound().y), data);
	this->drawPartialShadow(sf::Vector2i(data->getMinCoordBound().x, data->getMaxCoordBound().y), data);
	this->drawPartialShadow(data->getMaxCoordBound(), data);
}

void GlobalLight::drawPartialShadow(const sf::Vector2i &_bound, DataContainer *data)
{
	sf::Transform transform;

	transform.scale(1.f, RESIZE_TILE_Y);

	this->_shadow_tile[0].color = this->calcLightColor(this->coord.x, this->coord.y);
	this->_shadow_tile[1].color = this->calcLightColor(this->coord.x, _bound.y);
	this->_shadow_tile[2].color = this->calcLightColor(_bound.x, _bound.y);
	this->_shadow_tile[3].color = this->calcLightColor(_bound.x, this->coord.y);

	this->_shadow_tile[0].position = Tool::toWindowCoord(this->coord.x, this->coord.y, true);
	this->_shadow_tile[1].position = Tool::toWindowCoord(this->coord.x, _bound.y, true);
	this->_shadow_tile[2].position = Tool::toWindowCoord(_bound.x, _bound.y, true);
	this->_shadow_tile[3].position = Tool::toWindowCoord(_bound.x, this->coord.y, true);

	data->window->draw(this->_shadow_tile, transform);
}

sf::VertexArray & GlobalLight::getShadowTile()
{
	return this->_shadow_tile;
}

sf::Color		GlobalLight::calcLightColor(const short &posX, const short &posY) {
	float			distX = 0.0f;
	float			distY = 0.0f;

	distX = Tool::abs(posX - this->coord.x);
	distY = Tool::abs(posY - this->coord.y);

	return sf::Color(
		static_cast<unsigned char>(std::max(125 - ((distX + distY) * 15), 0.0f)),
		static_cast<unsigned char>(std::max(125 - ((distX + distY) * 15), 0.0f)),
		static_cast<unsigned char>(std::max(125 - ((distX + distY) * 15), 0.0f)),
		static_cast<unsigned char>(std::min((distX + distY) < 5 ? 0 : 255 - (140 - ((distX + distY) * 7)), 255.0f))
	);
}