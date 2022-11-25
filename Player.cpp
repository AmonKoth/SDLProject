#include "Player.h"


Player::Player(float x, float y, int width, int height, std::string textureID) :GameObject(x,y,width,height,textureID)
{

}


void Player::Draw(SDL_Renderer* pRenderer)
{
	GameObject::Draw(pRenderer);
}


void Player::Update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 9));

	m_acceleration.SetX(0.25);
	GameObject::Update();
}

void Player::Clean()
{

}