#pragma once
#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "TextureManager.h"

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
	
};


#endif // !GAME_H
