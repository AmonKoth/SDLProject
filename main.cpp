#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;


int main(int argc, char* argv[])
{
	Uint32 frameStart;
	Uint32 frameTime;

	std::cout << "Game creation attempt \n";
	if (TheGame::Instance()->Init("First Window", 100, 100, 640, 580, true))
	{
		while (TheGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();
			TheGame::Instance()->HandleEvents();
			TheGame::Instance()->Update();
			TheGame::Instance()->Renderer();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
			SDL_Delay((int) (DELAY_TIME-frameTime));
			}
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


