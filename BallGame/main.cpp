#include"Game.h"
#include"MainApplication.h"

int main()
{
	//init seed for rand()
	std::srand(static_cast<unsigned>(time(NULL)));

	MainApplication ma;

	ma.run();

	return 0;
}