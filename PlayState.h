#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameState.h"

class PlayState : public GameState
{
public:
	virtual void Update();
	virtual void Render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string GetStateID() const { return s_playStateID; }


private:
	static const std::string s_playStateID;

};

#endif // !PLAY_STATE_H
