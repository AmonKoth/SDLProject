#include "PlayState.h"

const std::string PlayState::s_playStateID = "Play";

void PlayState::Update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->GetGameStateMachine()->PushState(new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Update();
	}
}

void PlayState::Render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Draw(TheGame::Instance()->GetRenderer());
	}
}
bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->Load("assets/marco.png", "marco", TheGame::Instance()->GetRenderer()))
	{
		return false;
	}

	GameObject* player = new Player(100, 100, 32, 42, "marco");

	m_gameObjects.push_back(player);

	std::cout << "Entering PLay State\n";

	return true;
}
bool PlayState::onExit()
{

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->ClearFromTextureMap("marco");

	std::cout << "Play STate Exited\n";
	return true;
}


