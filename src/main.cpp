#include <iostream>
#include "Game.h"

Game* game = nullptr;
int main()
{
	std::cout << ("hello from main()") << std::endl;
	game = new Game();
	game->init();

	while (game->getIsRunning()) {
		game->render();
	}

	return 0;
}