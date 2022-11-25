#include "GameObject.h"

GameObject::GameObject(float x, float y, int width, int heigth, std::string textureID)
{
	m_position.SetX(x);
	m_position.SetY(y);
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

}


void GameObject::Clean()
{

}