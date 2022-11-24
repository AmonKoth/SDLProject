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

class Game
{
public:
	Game() {}
	~Game() {}

	bool Init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
	void Renderer();
	void Update();
	void HandleEvents();
	void Clean();
	bool running() { return m_bRunning; }

private:
	SDL_Window* mainWindow;
	SDL_Renderer* mainRenderer;
	
	bool m_bRunning;
	int currentFrame;
	

	GameObject* m_player;
	GameObject* m_enemy1;
	GameObject* m_enemy2;


	std::vector<GameObject*> m_gameObjects;
};


#endif // !GAME_H
