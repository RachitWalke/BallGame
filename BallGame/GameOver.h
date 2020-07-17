#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"state.h"
#include"Game.h"

class GameOver : public state,public Game
{
public:
	//cons and des
	GameOver();
	~GameOver();

	
	void update(sf::Vector2f mpos, int& StateID) override;
	void render(sf::RenderTarget& target) override;


private:
	//variables

	sf::Font font;
	sf::Text scoreDis;
	sf::Texture ScoreBtex;
	sf::Sprite ScoreB;
	sf::Texture GOtex;
	sf::Sprite GO;
	sf::Texture GOBackTex;
	sf::Sprite GOBack;
};

