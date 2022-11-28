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
	m_velocity.SetX(0);
	m_velocity.SetY(0);

	HandleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 9));
	
	GameObject::Update();
}

void Player::HandleInput()
{/*
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.SetX(1);
	}
	if (TheInputHandler::Instance()->getMouseButtonState(RIGHT))
	{
		m_velocity.SetX(-1);
	}
	*/
	Vector2D* vec = TheInputHandler::Instance()->getMousePos();
	m_velocity = (*vec - m_position) / 100;
}

void Player::Clean()
{

}