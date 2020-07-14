#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include<fstream>
#include<string>
#include<SFML/Graphics.hpp>
#include"MainMenu.h"
#include"PauseMenu.h"
#include"state.h"

//main game wrapper class (acts as game engine)

class Game : public state
{
private:
	/**
		Variables
	*/

	//window
	sf::FloatRect win;
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
	sf::Text pauseButton;
	sf::Text GameOversc;
	sf::Texture backgroundTex;
	sf::Sprite background;
	sf::Texture ballTex;
	sf::Texture spikeTex;
	sf::Texture platformTex;

	//private funcs
	void initvariables();
	void initplatform();
	void initball();
	void initGOsc();

public:

	//cons and des
	Game();
	~Game();

	//funcs
	void spawnplatform();
	void initSpike();
	void updateplatform();
	void moveBall();
	void updateBall();
	void updateplatspeed();
	void updateScore_Life();
	void renderBall_spike(sf::RenderTarget& target);
	void renderplatform(sf::RenderTarget& target);
	void update(sf::Vector2f mpos, int& StateID) override;
	void render(sf::RenderTarget& target) override;

};

