#include "GameOverState.h"

const std::string GameOverState::s_GameOverStateID = "GAMEOVER";

void GameOverState::s_GameOverToMain()
{
	TheGame::Instance()->GetGameStateMachine()->ChangeState(new MenuState());
}
void GameOverState::s_RestartPlay()
{
	TheGame::Instance()->GetGameStateMachine()->ChangeState(new PlayState());
}


bool GameOverState::onEnter()
{
	if (!TheTextureManager::Instance()->Load("assets/gameover.png", "gameoverText", TheGame::Instance()->GetRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->Load("assets/restart.png", "restartButton", TheGame::Instance()->GetRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->Load("assets/main.png", "mainmenuButton", TheGame::Instance()->GetRenderer()))
	{
		return false;
	}

	GameObject* gameOverText = new AnimatedGraphic(200, 100, 190, 30, "gameoverText", 2);
	GameObject* mainMenuButton = new MenuButton(200, 200, 200, 80, "mainmenuButton", s_GameOverToMain);
	GameObject* restartButton = new MenuButton(200, 300, 200, 80, "restartButton", s_RestartPlay);

	m_gameOverObjects.push_back(gameOverText);
	m_gameOverObjects.push_back(mainMenuButton);
	m_gameOverObjects.push_back(restartButton);

	std::cout << "entering GameoverState\n";

	return true;
}

void GameOverState::Update()
{
	for (int i = 0; i < m_gameOverObjects.size(); i++)
	{
		m_gameOverObjects[i]->Update();
	}
}

void GameOverState::Render()
{
	for (int i = 0; i < m_gameOverObjects.size(); i++)
	{
		m_gameOverObjects[i]->Draw(TheGame::Instance()->GetRenderer());
	}
}
bool GameOverState::onExit()
{
	for (int i = 0; i < m_gameOverObjects.size(); i++)
	{
		m_gameOverObjects[i]->Clean();
	}

	m_gameOverObjects.clear();
	TheTextureManager::Instance()->ClearFromTextureMap("gameoverText");
	TheTextureManager::Instance()->ClearFromTextureMap("mainmenuButton");
	TheTextureManager::Instance()->ClearFromTextureMap("restartButton");
	TheInputHandler::Instance()->Reset();

	std::cout << "Exiting GameOver state\n";
	return true;
}