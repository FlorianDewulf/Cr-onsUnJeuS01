#pragma once
#include <iostream>
#include <fstream>
#include "MapCase.hpp"
#include "SaveMapCase.hpp"
#include "AFileManager.hpp"

class LoadManager : public AFileManager
{
public:
	LoadManager();
	~LoadManager();

	virtual void	openFile(const std::string &);
	void			loadMap();
};

