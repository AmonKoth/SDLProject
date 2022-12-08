#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H

#include "GameState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"


class GameObject;

class GameOverState : public GameState
{
public:
	virtual void Update();
	virtual void Render();
	
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string GetStateID() const { return s_GameOverStateID; }


private:

	static void s_GameOverToMain();
	static void s_RestartPlay();

	static const std::string s_GameOverStateID;

	std::vector<GameObject*> m_gameOverObjects;


};

#endif // !GAME_OVER_STATE_H
