#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

#include "MenuState.h"
#include "PlayState.h"


class GameObject;

class PauseState : public GameState
{
public:

	virtual void Update() ;
	virtual void Render() ;

	virtual bool onEnter();
	virtual bool onExit() ;

	virtual std::string GetStateID() const { return s_pauseStateID; }


private:
	static void s_pauseToMain();
	static void s_resumeToPlay();

	static const std::string s_pauseStateID;

	std::vector<GameObject*> m_pauseMenuObjects;
};

#endif // !PAUSE_STATE_H
