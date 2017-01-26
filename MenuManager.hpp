#pragma once
#include <queue>
#include "ABasicElement.hpp"
#include "AWindow.hpp"
#include "DataContainer.hpp"
#include "InputStorage.hpp"

class InputStorage;

class MenuManager
{
public:
	MenuManager();
	~MenuManager();

public:
	void	processEvents(InputStorage &);
	void	clearWindows();
	bool	resetWindows();
	void	draw();

public:
	std::list<ABasicElement *>	_menu_elements;
	std::list<ABasicElement *>	_already_process;
};

