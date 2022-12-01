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

	void Reset();

	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

	Vector2D* getMousePos()
	{
		return m_mousePos;
	}

	bool isKeyDown(SDL_Scancode key);

private:

	InputHandler() {}
	~InputHandler() {}

	//Mouse
	void onMouseMove(SDL_Event& event);
	void onMouseButonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	Vector2D* m_mousePos = new Vector2D(0,0);
	std::vector<bool> m_mouseButtonStates;

	//Keyboard
	void onKeyDown();
	void onKeyUp();
	
	const Uint8* m_keyStates =0;

	static InputHandler* s_pInstance;

};

typedef InputHandler TheInputHandler;

#endif // !INPUT_HANDLER_H
