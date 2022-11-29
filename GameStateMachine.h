#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H

#include <vector>
#include "GameState.h"

class GameStateMachine
{

public:

	void PushState(GameState* gameState);
	void ChangeState(GameState* gameState);

	void PopState();

private:

	std::vector<GameState*> m_gameStateList;

};


#endif // !GAME_STATE_MACHINE_H
