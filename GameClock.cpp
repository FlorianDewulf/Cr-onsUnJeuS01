#include "GameClock.hpp"
#include <iostream>


GameClock::GameClock(const bool debug) : _debug(debug), _time(0), _frame(0), _lastTotalFrame(std::numeric_limits<int>::max())
{
	if (!this->_font.loadFromFile("arial.ttf")) {
		std::cerr << "Error while opening the font for debug" << std::endl;
		exit(-1);
	}
	this->_text.setFont(this->_font);
	this->_text.setCharacterSize(20);
	this->_text.setFillColor(sf::Color::White);
	this->_view.setCenter(0, 0);
	this->_text.setPosition(-75, -25);
	this->_view.setSize(200, 50);
	this->_view.setViewport(sf::FloatRect(0.0f, 0.0f, 0.13f, 0.05f));
	this->_text.setString("--- FPS");
}

GameClock::~GameClock()
{
}

void		GameClock::update(sf::Clock &clock) {
	this->_frame++;
	this->_time += clock.restart().asSeconds();

	if (this->_time > 1.0f) {
		this->_text.setString(std::to_string(this->_frame) + "FPS");
		this->_lastTotalFrame = std::max(this->_frame, 1);
		this->_frame = 0;
		this->_time = 0.0f;
	}
}

bool GameClock::isDebugEnable() const
{
	return this->_debug;
}

int GameClock::getFrameNumber() const
{
	return this->_frame;
}

int GameClock::getLastTotalFrame() const
{
	return this->_lastTotalFrame;
}

void GameClock::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::View	v = target.getView();

	target.setView(this->_view);
	target.draw(this->_text);

	target.setView(v);
}