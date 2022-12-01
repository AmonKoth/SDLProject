#include "Player.h"


Player::Player(float x, float y, int width, int height, std::string textureID) :GameObject(x,y,width,height,textureID)
{

}


void Player::Draw(SDL_Renderer* pRenderer)
{
	if (m_velocity.GetX() > 0)
	{
		TheTextureManager::Instance()->DrawFrame(m_textureID, (Uint32)m_position.GetX(), (Uint32)m_position.GetY(), m_width, m_height, m_currentRow, m_currentFrame,
			pRenderer);
	}
	else
	{
		TheTextureManager::Instance()->DrawFrame(m_textureID, (Uint32)m_position.GetX(), (Uint32)m_position.GetY(), m_width, m_height, m_currentRow, m_currentFrame,
			pRenderer, SDL_FLIP_HORIZONTAL);
	}
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
{
	//Mouse buton
	//if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	//{
	//	m_velocity.SetX(1);
	//}
	//if (TheInputHandler::Instance()->getMouseButtonState(RIGHT))
	//{
	//	m_velocity.SetX(-1);
	//}
	
	//Mouse
	Vector2D* target = TheInputHandler::Instance()->getMousePos();
	m_velocity = (*target - m_position) / 50;

	/*if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.SetX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.SetX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.SetY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.SetY(2);
	}*/
}

void Player::Clean()
{

}