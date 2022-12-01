#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "InputHandler.h"

class Player : public GameObject
{
public:
	Player(float x, float y, int width, int height, std::string textureID);
	~Player() {}
	
	void Draw(SDL_Renderer* pRenderer);
	void Update();
	void HandleInput();
	void Clean();
};


#endif // !PLAYER_H
