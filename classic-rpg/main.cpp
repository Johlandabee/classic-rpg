#include "Game.h"

int main(int argc, char *argv[], char *envp[])
{
	auto pGame = new Game();
	
	// Allocation check
	if(pGame)
	{
		// Enter main loop
		pGame->run();
	}
	
	delete pGame;
	return 0;
}
