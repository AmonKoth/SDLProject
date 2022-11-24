#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
class Enemy : public GameObject
{
public:

	void Load(int x, int y, int width ,int height, std::string textureID);
	void Draw(SDL_Renderer* pRenderer);
	void Update();
	void Clean();



};

#endif // !ENEMY_H
