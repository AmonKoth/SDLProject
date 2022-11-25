#include "Game.h"


bool Game::Init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_BORDERLESS;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL INIT SUCCESS\n";
		
		mainWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (mainWindow != 0)
		{
			std::cout << "Window create success \n";
			mainRenderer = SDL_CreateRenderer(mainWindow, -1, 0);
			if (mainRenderer != 0)
			{
				std::cout << "Renderer create success \n";
				SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 0);
			}
			else
			{
				std::cout << "Renderer init failed\n";
				return false;
			}
		}
		else
		{
			std::cout << "Window init failed \n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL init failed \n";
		return false;
	}
	std::cout << "Init success \n";
	m_bRunning = true;
	if (!TheTextureManager::Instance()->Load("assets/marco.png", "marco", mainRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->Load("assets/skelly.png", "skelly", mainRenderer))
	{
		return false;
	}

	m_gameObjects.push_back(new Player(10,20, 32, 42, "marco"));
	m_gameObjects.push_back(new Enemy(20, 20, 50, 45, "skelly"));
	m_gameObjects.push_back(new Enemy(20, 30, 50, 45, "skelly"));

	return true;
}

void Game::Renderer()
{

	SDL_RenderClear(mainRenderer);

	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Draw(mainRenderer);
	}
	SDL_RenderPresent(mainRenderer);
}

void Game::Clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(mainWindow);
	SDL_DestroyRenderer(mainRenderer);
	SDL_Quit();
}

void Game::HandleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::Update()
{
	currentFrame = int(((SDL_GetTicks() / 100) % 9));
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Update();
	}
}

Game* Game::s_pInstance = 0;