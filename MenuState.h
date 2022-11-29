#ifndef MENU_STATE_H
#define MENU_STATE_H


#include "GameState.h"
#include "GameObject.h"
#include "Game.h"
#include "MenuButton.h"

class MenuState : public GameState
{
public :
	virtual void Update();
	virtual void Render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string GetStateID() const { return s_menuStateID; }


private:

	static const std::string s_menuStateID;
	std::vector<GameObject*> m_menuObjects;

	SDL_Renderer* m_renderer;

};


#endif // !MENU_STATE_H
