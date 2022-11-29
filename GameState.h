#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
#include <iostream>
#include <vector>

class GameState
{
public:
	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual std::string GetStateID() const = 0;
};



#endif // !GAME_STATE_H
