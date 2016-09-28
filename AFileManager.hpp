#pragma once
#include <fstream>

class AFileManager
{
public:
	AFileManager();
	~AFileManager();

	virtual void			openFile(const std::string &) = 0;
	virtual void			closeFile();

protected:
	std::fstream			_file;
};

