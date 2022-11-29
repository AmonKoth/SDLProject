#include "MenuState.h"

const std::string MenuState::s_menuStateID = "MENU";

void MenuState::Update()
{

}

void MenuState::Render()
{
}

bool MenuState::onEnter()
{
	std::cout << "Menu State Entered\n";
	return true;
}
bool MenuState::onExit()
{
	std::cout << "Menu State Exited\n";
	return true;
}