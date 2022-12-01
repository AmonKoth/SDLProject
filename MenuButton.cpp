#include "MenuButton.h"


MenuButton::MenuButton(float x, float y, int width, int height, std::string textureID , void (*callback)()) :GameObject(x, y, width, height, textureID) , m_callback(callback)
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
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_currentFrame = CLICKED;
			m_callback();
			m_buttonReleased = false;
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_buttonReleased = true;
			m_currentFrame = MOUSE_OVER;
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