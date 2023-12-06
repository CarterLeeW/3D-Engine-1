#include <iostream>
#include "Game.h"

Game* game = nullptr;
int main()
{
	std::cout << ("hello from main()") << std::endl;
	game = new Game();
	game->init("title", 800, 600, false);

	while (game->getIsRunning()) {
		game->render();
	}

	return 0;
}