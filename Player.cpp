#include "Player.h"


Player::Player(int x, int y, int width, int height, std::string textureID) :GameObject(x,y,width,height,textureID)
{

}


void Player::Draw(SDL_Renderer* pRenderer)
{
	GameObject::Draw(pRenderer);
}


void Player::Update()
{
	m_position.SetX(m_position.GetX() +1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 9));
}

void Player::Clean()
{

}