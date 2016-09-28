#pragma once
#include "MapCase.hpp"

class MapCase;

struct SaveMapCase
{
	SaveMapCase();
	SaveMapCase(MapCase *);
	~SaveMapCase();

	unsigned short			id;
	int						x;
	int						y;
	char					depth;
};