#include "PlayState.h"

const std::string PlayState::s_playStateID = "Play";

void PlayState::Update()
{

}

void PlayState::Render()
{

}
bool PlayState::onEnter()
{
	std::cout << "Play STate Entered\n";
	return true;
}
bool PlayState::onExit()
{
	std::cout << "Play STate Exited\n";
	return true;
}


