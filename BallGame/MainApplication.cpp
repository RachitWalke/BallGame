#include "MainApplication.h"
#include"MainMenu.h"
#include"Game.h"
#include"PauseMenu.h"

MainApplication::MainApplication()
{

	window.create(sf::VideoMode(400, 700), "BALL GAME", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	StateID = 0;
	prevState = 0;
	changeState();
}

MainApplication::~MainApplication()
{
}

void MainApplication::run()
{
	while (window.isOpen())
	{
		if (prevState != StateID) changeState();
		prevState = StateID;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
		cState->update(sf::Vector2f(sf::Mouse::getPosition(window)), StateID);

		window.clear();
		cState->render(window);
		window.display();
	}
}

void MainApplication::closeApplication()
{
	window.close();
}

void MainApplication::changeState()
{
	switch (StateID)
	{
	case -1: window.close();
		break;
	case 0: cState = &ss;
		break;
	case 1: cState = &mainmenu;
		break;
	case 2: cState = &game;
		break;
	case 3: cState = &pausemenu;
		break;
	case 4: cState = &gameover;
		gameover.setScore(game.getScore());
		game.reset();
	default:
		break;
	}
}
