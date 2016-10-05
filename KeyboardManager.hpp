#pragma once
#include <list>
#include <map>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Enum.hpp"
#include "DataContainer.hpp"

class DataContainer;

class KeyboardManager
{
public:
	KeyboardManager();
	~KeyboardManager();

	void		eventStorage(const sf::Event &);
	void		eventInterpreter();

/**
 * Method for the method pointer
 */
private:
	void		moveForward(void *) const;
	void		moveLeft(void *) const;
	void		moveBackward(void *) const;
	void		moveRight(void *) const;
	void		closeWindow(void *) const;
	void		zoom(void * data) const;
	void		unzoom(void * data) const;
	void		fire(void * data) const;
	void		ice(void * data) const;
	void		rocket(void * data) const;
	void		slime(void * data) const;


private:
	std::map<sf::Keyboard::Key, KeyConstants>						input_mapping;
	std::list<KeyConstants>											actions;
	std::map<KeyConstants, void (KeyboardManager::*)(void *) const> process_method_map;
};

