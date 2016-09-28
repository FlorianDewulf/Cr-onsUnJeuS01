#include "SaveMapCase.hpp"

SaveMapCase::SaveMapCase()
{
}

SaveMapCase::SaveMapCase(MapCase *_case)
{
	this->id = _case->id;
	this->x = _case->humanCoord.x;
	this->y = _case->humanCoord.y;
	this->depth = _case->depth;
}


SaveMapCase::~SaveMapCase()
{
}
