#include "MenuState.h"

const std::string MenuState::s_menuStateID = "MENU";

void MenuState::Update()
{
	for (int i = 0; i < m_menuObjects.size(); i++)
	{
		m_menuObjects[i]->Update();
	}
}

void MenuState::Render()
{
	for (int i = 0; i < m_menuObjects.size(); i++)
	{
		m_menuObjects[i]->Draw(TheGame::Instance()->GetRenderer());
	}
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->Load("assets/play.png", "playbutton", TheGame::Instance()->GetRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->Load("assets/exit.png", "exitbutton", TheGame::Instance()->GetRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(100,100,400,100,"playbutton", s_menuToPlay);
	GameObject* button2 = new MenuButton(100,300,400,100,"exitbutton", s_exitFromMenu);

	m_menuObjects.push_back(button1);
	m_menuObjects.push_back(button2);

	std::cout << "Entering menu State\n";
	return true;

}
bool MenuState::onExit()
{
	for (int i = 0; i < m_menuObjects.size(); i++)
	{
		m_menuObjects[i]->Clean();
	}
	m_menuObjects.clear();
	TheTextureManager::Instance()->ClearFromTextureMap("playbutton");
	TheTextureManager::Instance()->ClearFromTextureMap("exitbutton");

	std::cout << "Exiting menu State\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->GetGameStateMachine()->ChangeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->QuitGame();
}