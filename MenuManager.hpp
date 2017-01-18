#pragma once
#include <queue>
#include "ABasicElement.hpp"
#include "AClickable.hpp"
#include "AInputable.hpp"
#include "ASelectable.hpp"
#include "AScrollable.hpp"
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
	bool	resetWindows();

protected:
	std::list<ABasicElement *>	_menu_elements;
	std::list<ABasicElement *>	_already_process;
};

