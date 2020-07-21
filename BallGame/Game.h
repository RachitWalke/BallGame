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
	sf::Text pauseButton;
	sf::Texture backgroundTex;
	sf::Sprite background;
	sf::Texture ballTex;
	sf::Texture spikeTex;
	sf::Texture platformTex;

	//UI / HUD
	sf::Texture PauseTex;
	sf::Sprite PauseB;
	sf::Texture lifeFillTex;
	sf::Sprite FillLife1;
	sf::Sprite FillLife2;
	sf::Sprite FillLife3;
	sf::Texture lifeEmpTex;
	sf::Sprite EmpLife1;
	sf::Sprite EmpLife2;
	sf::Sprite EmpLife3;
	sf::Texture ScoreFieldTex;
	sf::Sprite ScoreField;


	//private funcs
	void initvariables();
	void initplatform();
	void initball();
	void initHearts();
	void initLevel2();
	void initLevel3();

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
	int  getScore();
	//void reset();
	void renderBall_spike(sf::RenderTarget& target);
	void renderplatform(sf::RenderTarget& target);
	void update(sf::Vector2f mpos, int& StateID) override;
	void render(sf::RenderTarget& target) override;

};

