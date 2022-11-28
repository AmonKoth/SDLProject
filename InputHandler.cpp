#include "InputHandler.h"

void InputHandler::InitializeController()
{
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}

void InputHandler::Update()
{
	m_keyStates = SDL_GetKeyboardState(0);
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->QuitGame();
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}
}

void InputHandler::onMouseMove(SDL_Event& event)
{
	m_mousePos->SetX(event.motion.x);
	m_mousePos->SetY(event.motion.y);
}

void InputHandler::onMouseButonDown(SDL_Event& event)
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

void InputHandler::onMouseButtonUp(SDL_Event& event)
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

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keyStates == 0)
	{
		return false;
	}

	if (m_keyStates[key] == 1)
	{
		return true;
	}
	return false;
}

void InputHandler::onKeyDown()
{

}
void InputHandler::onKeyUp()
{

}


void InputHandler::Clean()
{

}


InputHandler* InputHandler::s_pInstance = 0;