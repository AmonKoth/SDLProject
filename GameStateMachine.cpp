#include "GameStateMachine.h"

void GameStateMachine::PushState(GameState* gameState)
{
	m_gameStateList.push_back(gameState);
	m_gameStateList.back()->onEnter();
}

void GameStateMachine::PopState()
{
	if (!m_gameStateList.empty())
	{
		return;
	}
	if (m_gameStateList.back()->onExit())
	{
		delete m_gameStateList.back();
		m_gameStateList.pop_back();
	}
}

void GameStateMachine::ChangeState(GameState* gameState)
{
	if (!m_gameStateList.empty())
	{
		if (m_gameStateList.back()->GetStateID() == gameState->GetStateID())
		{
			return;
		}
		if (m_gameStateList.back()->onExit())
		{
			delete m_gameStateList.back();
			m_gameStateList.pop_back();
		}
	}

	m_gameStateList.push_back(gameState);
	m_gameStateList.back()->onEnter();
}