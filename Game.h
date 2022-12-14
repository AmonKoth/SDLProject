#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GameStateMachine.h"

class Game
{
public:
	~Game() {}

	bool Init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
	void Renderer();
	void Update();
	void HandleEvents();
	void Clean();
	void QuitGame();
	bool running() { return m_bRunning; }

	GameStateMachine* GetGameStateMachine() { return m_gameStateMachine; }

	SDL_Renderer* GetRenderer() { return mainRenderer; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	Game() {}
	SDL_Window* mainWindow;
	SDL_Renderer* mainRenderer;
	
	bool m_bRunning;

	static Game* s_pInstance;
	
	std::vector<GameObject*> m_gameObjects;
	GameStateMachine* m_gameStateMachine;
};

typedef Game TheGame;


#endif // !GAME_H
