#include "NPC.hpp"
#include "MapCase.hpp"
#include <iostream>

NPC::NPC() : ACharacter()
{
	this->_position.x = rand() % 20 + 1.0f;
	this->_position.y = rand() % 20 + 1.0f;

	this->move(this->_position);
	this->findCase();
}

NPC::~NPC()
{
}
