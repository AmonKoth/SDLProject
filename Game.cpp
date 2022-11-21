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
	return true;
}

void Game::Renderer()
{

	SDL_RenderClear(mainRenderer);
	TheTextureManager::Instance()->Draw("marco", 0, 0, 32, 42, mainRenderer);
	TheTextureManager::Instance()->DrawFrame("marco", 50, 50, 32, 42, 1, currentFrame, mainRenderer);
	TheTextureManager::Instance()->DrawFrame("marco", 100, 50, 32, 42, 1, currentFrame, mainRenderer);
	TheTextureManager::Instance()->DrawFrame("marco", 150, 50, 32, 42, 1, currentFrame, mainRenderer);
	TheTextureManager::Instance()->DrawFrame("marco", 200, 50, 32, 42, 1, currentFrame, mainRenderer);
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
}