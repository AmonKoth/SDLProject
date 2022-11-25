#include "Enemy.h"

 Enemy::Enemy(float x, float y, int width, int height, std::string textureID) : GameObject(x,y,width,height,textureID)
{

}


void Enemy::Draw(SDL_Renderer* pRenderer)
{
	GameObject::Draw(pRenderer);
}


void Enemy::Update()
{

	m_currentFrame = int(((SDL_GetTicks() / 100) % 9));

	m_velocity.SetX(1);
	m_velocity.SetY(1);

	GameObject::Update();
}

void Enemy::Clean()
{

}