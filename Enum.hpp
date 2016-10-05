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

#ifndef __TEXTURE_CONSTANTS
#define __TEXTURE_CONSTANTS
	extern TextureConstants texture_constants[] = {FLOOR, GRASS, DIRT, WATER, NO_TEXTURE };
#endif