#pragma once
#include <string>

enum KeyConstants {
	FORWARD = 1,
	BACKWARD,
	LEFT,
	RIGHT,
	ESCAPE,
	PLUS,
	MINUS,
	FIRE,
	ICE,
	ROCKET,
	SLIME
};

enum TextureConstants {
	NO_TEXTURE = 0,
	FLOOR,
	GRASS,
	DIRT,
	WATER
};

enum SoundConstants {
	NO_SOUND = 0,
	FIRE_SOUND,
	ICE_SOUND,
	ROCKET_SOUND,
	SLIME_SOUND
};

enum MusicConstants {
	NO_MUSIC = 0,
	MUSIC_DEFAULT
};

extern TextureConstants texture_constants[];
extern SoundConstants	sound_constants[];
extern std::string		sound_filename_constants[];
extern MusicConstants	music_constants[];
extern std::string		music_filename_constants[];