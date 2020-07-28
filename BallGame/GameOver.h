#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"state.h"
#include"Game.h"

class GameOver : public state
{
public:
	//cons and des
	GameOver();
	~GameOver();

	
	void update(sf::Vector2f mpos, int& StateID) override;
	void render(sf::RenderTarget& target) override;
	void setScore(int score);


private:
	//variables

	sf::Font font;
	sf::Text ScoreDis;
	sf::Text MM;
	sf::Texture MMtex;
	sf::Sprite MMb;
	sf::Texture ScoreBtex;
	sf::Sprite ScoreB;
	sf::Texture GOtex;
	sf::Sprite GO;
	sf::Texture GOBackTex;
	sf::Sprite GOBack;
};

