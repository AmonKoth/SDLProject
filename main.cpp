#include "Game.h"

Game* g_game = 0;

int main(int argc, char* argv[])
{
	g_game = new Game();
	if (g_game->Init("First Window", 100, 100, 640, 580, true))
	{
	while (g_game->running())
	{
		g_game->HandleEvents();
		g_game->Update();
		g_game->Renderer();
	}
	g_game->Clean();

	}
	return 0;

}


