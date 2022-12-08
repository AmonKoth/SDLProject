#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameState.h"
#include "Player.h"
#include "Enemy.h"
#include "PauseState.h"
#include "GameOverState.h"

class PlayState : public GameState
{
public:
	virtual void Update();
	virtual void Render();

	virtual bool onEnter();
	virtual bool onExit();

	bool CheckCollision(GameObject* p1, GameObject* p2);

	virtual std::string GetStateID() const { return s_playStateID; }


private:
	static const std::string s_playStateID;

	std::vector<GameObject*> m_gameObjects;

};

#endif // !PLAY_STATE_H
