#include "MenuButton.h"


MenuButton::MenuButton(float x, float y, int width, int height, std::string textureID) :GameObject(x, y, width, height, textureID)
{
	m_currentFrame = MOUSE_OUT;
}

void MenuButton::Draw(SDL_Renderer* pRenderer)
{
	GameObject::Draw(pRenderer);
}

void MenuButton::Update()
{
	Vector2D* pmousePos = TheInputHandler::Instance()->getMousePos();

	if (pmousePos->GetX() < (m_position.GetX() + m_width) && pmousePos->GetX() > m_position.GetX() &&
		pmousePos->GetY() < (m_position.GetY() + m_height) && pmousePos->GetY() > m_position.GetY())
	{
		m_currentFrame = MOUSE_OVER;
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_currentFrame = CLICKED;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::Clean()
{
	GameObject::Clean();
}