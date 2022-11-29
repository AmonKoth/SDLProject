#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include "GameObject.h"
#include "InputHandler.h"


enum button_state
{
	MOUSE_OUT = 1,
	MOUSE_OVER = 2,
	CLICKED = 3
};

class MenuButton :public GameObject
{
public:
	MenuButton(float x, float y, int width, int heigth, std::string textureID);
	
	virtual void Draw(SDL_Renderer* pRenderer);
	virtual void Update();
	virtual void Clean();



};



#endif // !MENU_BUTTON_H
