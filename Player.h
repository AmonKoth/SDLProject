#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include"GameObject.h"

class Player : public GameObject
{
public:
	 Player() {}
	~Player() {}
	
	void Load(int x, int y, int width, int height, std::string textureID);
	void Draw(SDL_Renderer* pRenderer);
	void Update();
	void Clean();

};


#endif // !PLAYER_H
