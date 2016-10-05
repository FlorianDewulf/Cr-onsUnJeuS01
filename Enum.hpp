#pragma once

enum KeyConstants {
	FORWARD = 1,
	BACKWARD,
	LEFT,
	RIGHT,
	ESCAPE,
	PLUS,
	MINUS
};

enum TextureConstants {
	NO_TEXTURE = 0,
	FLOOR,
	GRASS,
	DIRT,
	WATER
};

extern TextureConstants texture_constants[];