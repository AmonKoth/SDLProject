#include "GameObject.h"

void GameObject::Load(int x, int y, int width, int heigth, std::string textureID)
{
	m_xCoord = x;
	m_yCoord = y;
	m_width = width;
	m_height = heigth;

	m_textureID = textureID;

	m_currentFrame = 1;
	m_currentRow = 1;
}


void GameObject::Draw(SDL_Renderer* pRenderer)
{
	TheTextureManager::Instance()->DrawFrame(m_textureID, m_xCoord, m_yCoord, m_width, m_height, m_currentRow, m_currentFrame,
		pRenderer);
}

void GameObject::Update()
{
	m_xCoord += 1;
}


void GameObject::Clean()
{

}