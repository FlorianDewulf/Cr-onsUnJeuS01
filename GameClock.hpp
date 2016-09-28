#pragma once
#include	<SFML/Graphics.hpp>

class GameClock : public sf::Drawable
{
public:
	GameClock(const bool);
	~GameClock();

	void		update(sf::Clock & clock);

	bool		isDebugEnable() const;
	int			getFrameNumber() const;

	int			getLastTotalFrame() const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	bool		_debug;
	float		_time;
	int			_frame;
	int			_lastTotalFrame;
	sf::Font	_font;
	sf::Text	_text;
	sf::View	_view;
};

