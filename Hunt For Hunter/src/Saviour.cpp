#include "Saviour.h"
#include"SDL.h"


Saviour::Saviour()
{
}


Saviour::~Saviour()
{
}

void Saviour::init(float speed, glm::vec2 pos, GameEngine::keyHandler* _keyHandler)
{
	_speed = speed;
	_position = pos;
	_keyHandler = _keyHandler;
	_color.r = 242;
	_color.g = 147;
	_color.b = 106;
	_color.a = 255;


}

void Saviour::update()
{
	if (_keyHandler->iskeyPressed(SDLK_w))
	{
		_position.y -= _speed;
	}
	else if (_keyHandler->iskeyPressed(SDLK_s))
	{
		_position.y += _speed;
	}
	if (_keyHandler->iskeyPressed(SDLK_a))
	{
		_position.x -= _speed;
	}
	else if (_keyHandler->iskeyPressed(SDLK_d))
	{
		_position.x += _speed;
	}
}