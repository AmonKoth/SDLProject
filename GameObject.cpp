#include "GameObject.h"

GameObject::GameObject(float x, float y, int width, int heigth, std::string textureID) : m_position(x,y), m_velocity(0, 0)
{
	m_width = width;
	m_height = heigth;

	m_textureID = textureID;

	m_currentFrame = 1;
	m_currentRow = 1;
}


void GameObject::Draw(SDL_Renderer* pRenderer)
{
	TheTextureManager::Instance()->DrawFrame(m_textureID, m_position.GetX(), m_position.GetY(), m_width, m_height, m_currentRow, m_currentFrame,
		pRenderer);
}

void GameObject::Update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}


void GameObject::Clean()
{

}