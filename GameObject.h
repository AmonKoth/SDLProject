#pragma once
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include "TextureManager.h"

class GameObject
{

public:

	GameObject(int x, int y, int width, int height, std::string textureID);
	~GameObject() {}

	virtual void Draw(SDL_Renderer* pRenderer );
	virtual void Update();
	virtual void Clean();



protected:

	int m_xCoord;
	int m_yCoord;

	int m_width;
	int m_height;

	std::string m_textureID;

	int m_currentFrame;
	int m_currentRow;
};





#endif // !GAME_OBJECT_H
