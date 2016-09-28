#include "AFileManager.hpp"



AFileManager::AFileManager()
{
}


AFileManager::~AFileManager()
{
}

void AFileManager::closeFile()
{
	this->_file.close();
}
