#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
class Enemy : public GameObject
{
public:

	Enemy(float x, float y, int width, int height, std::string textureID);
	~Enemy() {};

	void Draw(SDL_Renderer* pRenderer);
	void Update();
	void Clean();



};

#endif // !ENEMY_H
