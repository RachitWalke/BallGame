#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include<fstream>
#include<string>
#include<SFML/Graphics.hpp>
//#include<SFML/Window.hpp>
//#include<SFML/System.hpp>
#include"MainMenu.h"
#include"PauseMenu.h"

//main game wrapper class (acts as game engine)

class Game
{
private:
	/**
		Variables
	*/

	//window
	sf::RenderWindow window;
	sf::Event event;

	//platform Game logic
	float platSpwanTimer;
	float platSpwanTimerMax;
	int maxPlat;
	float platspeed;
	float pointf;
	int pointi;
	int n;
	int health;
	bool gameover;
	std::string getHS;
	int checkHS;
	std::fstream obj;
	sf::Vector2f velocity;

	//Game Objects
	std::vector<sf::Sprite> platforms;
	std::vector<sf::Sprite> spikes;
	sf::Sprite platform;
	sf::Sprite spike;
	sf::RectangleShape spikebase;
	sf::Sprite ball;
	sf::Font font;
	sf::Text score;
	sf::Text life;
	sf::Text high;
	sf::Text GameOversc;
	sf::Texture backgroundTex;
	sf::Sprite background;
	sf::Texture ballTex;
	sf::Texture spikeTex;
	sf::Texture platformTex;

	MainMenu mm;
	PauseMenu pm;

	//private funcs
	void initvariables();
	void initplatform();
	void initball();
	void initwindow();
	void initGOsc();

public:

	//cons and des
	Game();
	~Game();

	//accesscors

	const bool running() const;
	const bool getGameover() const;


	//funcs
	void pollEvents();
	void spawnplatform();
	void initSpike();
	void updateplatform();
	void moveBall();
	void updateBall();
	void updateplatspeed();
	void updateScore_Life();
	void renderBall_spike(sf::RenderTarget& target);
	void renderplatform(sf::RenderTarget& target);
	void highScore();
	void menu();
	void update();
	void render();

};

