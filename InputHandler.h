#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL.h>
#include <iostream>
#include <vector>

#include "Game.h"


enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		return s_pInstance;
		}
		return s_pInstance;
	}

	void InitializeController();

	void Update();
	void Clean();

	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

private:


	InputHandler() {}
	~InputHandler() {}

	static InputHandler* s_pInstance;

	std::vector<bool> m_mouseButtonStates;


};

typedef InputHandler TheInputHandler;

#endif // !INPUT_HANDLER_H
