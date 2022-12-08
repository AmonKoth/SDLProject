#include "Enemy.h"

 Enemy::Enemy(float x, float y, int width, int height, std::string textureID) : GameObject(x,y,width,height,textureID)
{
	 m_velocity.SetY(2);
	 m_velocity.SetX(0.001);
}


void Enemy::Draw(SDL_Renderer* pRenderer)
{
	GameObject::Draw(pRenderer);
}


void Enemy::Update()
{

	m_currentFrame = int(((SDL_GetTicks() / 100) % 9));
	if (m_position.GetY() < 0)
	{
		m_velocity.SetY(2);
	}
	else if (m_position.GetY() > 400)
	{
		m_velocity.SetY(-2);
	}

	GameObject::Update();
}

void Enemy::Clean()
{

}