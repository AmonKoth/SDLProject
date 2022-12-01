#include "PauseState.h"

const std::string PauseState::s_pauseStateID = "PAUSE";

void PauseState::Update()
{
	for (int i = 0; i < m_pauseMenuObjects.size(); i++)
	{
		m_pauseMenuObjects[i]->Update();
	}
}

void PauseState::Render()
{
	for (int i = 0; i < m_pauseMenuObjects.size(); i++)
	{
		m_pauseMenuObjects[i]->Draw(TheGame::Instance()->GetRenderer());
	}
}
	  
bool PauseState::onEnter()
{
	if (!TheTextureManager::Instance()->Load("assets/main.png", "mainbutton", TheGame::Instance()->GetRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->Load("assets/resume.png", "resumebutton", TheGame::Instance()->GetRenderer()))
	{
		return false;
	}
	GameObject* mainButton = new MenuButton(200, 100, 200, 80, "mainbutton", s_pauseToMain);
	GameObject* resumeButton = new MenuButton(200, 300, 200, 80, "resumebutton", s_resumeToPlay);

	m_pauseMenuObjects.push_back(mainButton);
	m_pauseMenuObjects.push_back(resumeButton);

	std::cout << "entering pause state\n";
	return true;

}

bool PauseState::onExit()
{
	for (int i = 0; i < m_pauseMenuObjects.size(); i++)
	{
		m_pauseMenuObjects[i]->Clean();
	}

	m_pauseMenuObjects.clear();
	TheTextureManager::Instance()->ClearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->ClearFromTextureMap("resumebutton");
	TheInputHandler::Instance()->Reset();

	std::cout << "Exiting pause state\n";
	return true;
}
	  
void PauseState::s_pauseToMain()
{

	TheGame::Instance()->GetGameStateMachine()->ChangeState(new MenuState());
}

void PauseState::s_resumeToPlay()
{
	TheGame::Instance()->GetGameStateMachine()->PopState();
}
