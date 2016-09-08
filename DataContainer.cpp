#include "DataContainer.hpp"
DataContainer *DataContainer::_instance;


DataContainer::DataContainer()
{
}

DataContainer & DataContainer::operator=(const DataContainer &old_data)
{
	this->window = old_data.window;
	this->light.coord = old_data.light.coord;
	this->map = old_data.map;

	return *this;
}

DataContainer::DataContainer(const DataContainer &old_data)
{
	this->window = old_data.window;
	this->light.coord = old_data.light.coord;
	this->map = old_data.map;
}


DataContainer::~DataContainer()
{
	if (DataContainer::_instance) {
		delete DataContainer::_instance;
	}
}

DataContainer *DataContainer::getInstance()
{
	if (!DataContainer::_instance) {
		DataContainer::_instance = new DataContainer();
	}

	return DataContainer::_instance;
}

void		DataContainer::init(sf::RenderWindow * const new_window, const short &width, const short &height, const sf::Texture &texture)
{
	this->window = new_window;
	this->map = new IsometricMap(width, height, texture);
	this->updateView();
}

void DataContainer::updateView()
{
	sf::View view = this->window->getView();
	view.setCenter(Tool::toWindowCoord(this->light.coord.x, this->light.coord.y));
	this->window->setView(view);
}
