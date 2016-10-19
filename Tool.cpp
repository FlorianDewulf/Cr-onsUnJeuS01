#include "Tool.hpp"

namespace Tool {
	sf::Vector2f toWindowCoord(const float &x, const float &y, const bool with_transformation)
	{
		return sf::Vector2f(
			x * (calcWidthAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE) / 2) - (calcWidthAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE) / 2 * y),
			(x + y) * (calcHeightAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE) * (with_transformation ? 1 : RESIZE_TILE_Y)) / 2
		);
	}

	sf::Vector2i toDataCoord(const float &x, const float &y, const bool with_transformation)
	{
		float tileX = calcWidthAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE);
		float tileY = calcHeightAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE);
		float new_y = (-x + ((y * 2) / (tileY * (with_transformation ? 1 : RESIZE_TILE_Y)) * (tileY / 2))) / ((tileY / 2) + (tileX / 2));

		return sf::Vector2i(
			(int)(((2 * y) - new_y * (tileY * (with_transformation ? 1 : RESIZE_TILE_Y))) / (tileY * (with_transformation ? 1 : RESIZE_TILE_Y))),
			(int)new_y
		);
	}

	sf::Vector2f toDataCoordF(const float & x, const float & y, const bool with_transformation)
	{
		float tileX = calcWidthAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE);
		float tileY = calcHeightAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE);
		float new_y = (-x + ((y * 2.f) / (tileY * (with_transformation ? 1.f : RESIZE_TILE_Y)) * (tileY / 2.f))) / ((tileY / 2.f) + (tileX / 2.f));

		return sf::Vector2f(
			((2 * y) - new_y * (tileY * (with_transformation ? 1.f : RESIZE_TILE_Y))) / (tileY * (with_transformation ? 1.f : RESIZE_TILE_Y)),
			new_y
			);
	}

	float toDegree(const float &a)
	{
		return a / M_PI * 180;
	}

	float toRad(const float &a)
	{
		return a / 180 * M_PI;
	}

	float abs(const float &number)
	{
		if (number < 0) {
			return number * -1;
		}
		return number;
	}

	sf::Vector2f calcSizeAfterRotation(const float &width, const float &height, const float &angle_deg)
	{
		return sf::Vector2f(
			calcWidthAfterRotation(width, height, angle_deg),
			calcHeightAfterRotation(width, height, angle_deg)
		);
	}

	float calcWidthAfterRotation(const float &width, const float &height, const float &angle_deg)
	{
		return width * cos(toRad(angle_deg)) + height * sin(toRad(angle_deg));
	}

	float calcHeightAfterRotation(const float &width, const float &height, const float &angle_deg)
	{
		return width * sin(toRad(angle_deg)) + height * cos(toRad(angle_deg));
	}

	bool isInBoundDataCoord(const sf::Vector2i &position, const sf::Vector2i &min_position, const sf::Vector2i &max_position)
	{
		return (position.x > min_position.x && position.y > min_position.y && position.x < max_position.x && position.y < max_position.y);
	}

	float pythagore_hypothenuse(float & a, float & b)
	{
		return sqrt(a*a + b*b);
	}


}