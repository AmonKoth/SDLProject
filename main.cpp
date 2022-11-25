#include "Game.h"

int main(int argc, char* argv[])
{
	std::cout << "Game creation attempt \n";
	if (TheGame::Instance()->Init("First Window", 100, 100, 640, 580, true))
	{
		while (TheGame::Instance()->running())
		{
			TheGame::Instance()->HandleEvents();
			TheGame::Instance()->Update();
			TheGame::Instance()->Renderer();
			SDL_Delay(10);
		}
	}
	else
	{
		std::cout << "Init failed " << SDL_GetError() <<" \n";
		return -1;
	}

	std::cout << "Game Closing\n";
	TheGame::Instance()->Clean();
	return 0;

}


