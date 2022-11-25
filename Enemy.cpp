#include "Enemy.h"

 Enemy::Enemy(int x, int y, int width, int height, std::string textureID) : GameObject(x,y,width,height,textureID)
{

}


void Enemy::Draw(SDL_Renderer* pRenderer)
{
	GameObject::Draw(pRenderer);
}


void Enemy::Update()
{
	m_xCoord += 1;
	m_yCoord += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 9));
}

void Enemy::Clean()
{

}