#include "Tool.hpp"

namespace Tool {
	sf::Vector2f toWindowCoord(const float &x, const float &y, const bool with_transformation)
	{
		return sf::Vector2f(
			x * (calcWidthAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE) / 2) - (calcWidthAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE) / 2 * y),
			(x + y) * (calcHeightAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE) * (with_transformation ? 1 : RESIZE_TILE_Y)) / 2
		);
	}

	sf::Vector2f toDataCoord(const float &x, const float &y, const short &width_case, const short &height_case)
	{
		return sf::Vector2f(x, y);
	}
	float toDegree(const float &a)
	{
		return a / M_PI * 180;
	}
	float toRad(const float &a)
	{
		return a / 180 * M_PI;
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
}