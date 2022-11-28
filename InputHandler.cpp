#include "InputHandler.h"

void InputHandler::InitializeController()
{
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
	m_mousePos = new Vector2D(0, 0);
}

void InputHandler::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{

			TheGame::Instance()->QuitGame();
		}
		if (event.type == SDL_MOUSEMOTION)
		{
			m_mousePos->SetX(event.motion.x);
			m_mousePos->SetY(event.motion.y);
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = true;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = true;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = true;
			}
		}
		if (event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = false;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = false;
			}
		}

	}
}


void InputHandler::Clean()
{

}


InputHandler* InputHandler::s_pInstance = 0;