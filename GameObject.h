#pragma once
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include "TextureManager.h"
#include "Vector2D.h"


class GameObject
{

public:

	GameObject(float x, float y, int width, int height, std::string textureID);
	~GameObject() {}

	virtual void Draw(SDL_Renderer* pRenderer );
	virtual void Update();
	virtual void Clean();

	Vector2D& GetPosition() { return m_position; }
	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }



protected:

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_width;
	int m_height;

	std::string m_textureID;

	int m_currentFrame;
	int m_currentRow;
};





#endif // !GAME_OBJECT_H
