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

	if (CheckCollision(dynamic_cast<GameObject*>(m_gameObjects[0]), dynamic_cast<GameObject*>(m_gameObjects[1])))
	{
		TheGame::Instance()->GetGameStateMachine()->PushState(new GameOverState());
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
	if (!TheTextureManager::Instance()->Load("assets/skelly.png", "skelly", TheGame::Instance()->GetRenderer()))
	{
		return false;
	}

	GameObject* player = new Player(100, 100, 32, 42, "marco");
	GameObject* enemy = new Enemy(500, 100, 50, 45,"skelly");

	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);

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

bool PlayState::CheckCollision(GameObject* p1,GameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int upA, upB;
	int downA, downB;

	leftA = p1->GetPosition().GetX();
	rightA = p1->GetPosition().GetX() + p1->GetWidth();
	upA = p1->GetPosition().GetY();
	downA = p1->GetPosition().GetY() + p1->GetHeight();

	leftB = p2->GetPosition().GetX();
	rightB = p2->GetPosition().GetX() + p2->GetWidth();
	upB = p2->GetPosition().GetY();
	downB = p2->GetPosition().GetY() + p2->GetHeight();

	if (downA <= upB) { return false; }
	if (upA >= downB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }

	return true;
}

