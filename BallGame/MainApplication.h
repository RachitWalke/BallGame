#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<memory>
#include"state.h"
#include"MainMenu.h"
#include"Game.h"
#include"PauseMenu.h"
#include"GameOver.h"
#include"SplashScreen.h"

class MainApplication
{

public:
	MainApplication();
	~MainApplication();

	void run();

	void closeApplication();

private:

	sf::RenderWindow window;

	SplashScreen ss;
	Game game;
	MainMenu mainmenu;
	PauseMenu pausemenu;
	GameOver gameover;

	void changeState();
	state* cState;
	int StateID;
	int prevState;
};

