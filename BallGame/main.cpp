#include"Game.h"
#include"MainMenu.h"

int main()
{
	//init seed for rand()
	std::srand(static_cast<unsigned>(time(NULL)));

	//init Game engine
	Game game;
	//game loop
	while (game.running())
	{
		game.pollEvents();
		game.menu();
	}

	return 0;
}