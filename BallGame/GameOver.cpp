#include "GameOver.h"

GameOver::GameOver()
{
	font.loadFromFile("FONTS/comic.ttf");

	//Display Game over
	GOBackTex.loadFromFile("SPRITES/menu.png");
	GOBack.setTexture(GOBackTex);
	GOtex.loadFromFile("SPRITES/gameover.png");
	GO.setTexture(GOtex);
	GO.setScale(0.65f, 0.65f);
	GO.setPosition(25.f, 90.f);

	//score button 
	ScoreBtex.loadFromFile("SPRITES/f.png");
	ScoreB.setTexture(ScoreBtex);
	ScoreB.setScale(0.2f, 0.15f);
	ScoreB.setPosition(40.f, 350.f);

	//current score
	ScoreDis.setFont(font);
	ScoreDis.setFillColor(sf::Color(100, 149, 273, 255));
	ScoreDis.setCharacterSize(40);

	//mainmenu button
	MM.setFont(font);
	MM.setCharacterSize(45);
	MM.setPosition(90.f - MM.getGlobalBounds().width / 2.f, 567.f - MM.getGlobalBounds().height / 2.f);
	MM.setString("MainMenu");
	MM.setFillColor(sf::Color::Cyan);

	MMtex.loadFromFile("SPRITES/b_5.png");
	MMb.setTexture(MMtex);
	MMb.setScale(0.46f, 0.3f);
	MMb.setPosition(197.f - MMb.getGlobalBounds().width / 2.f, 600.f - MMb.getGlobalBounds().height / 2.f);
}

GameOver::~GameOver()
{
}

void GameOver::update(sf::Vector2f mpos, int & StateID)
{
	if ((MMb.getGlobalBounds().contains(mpos)))
	{
		MM.setFillColor(sf::Color(255, 69, 0, 255));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			StateID = 0;
		}
	}
	else
		MM.setFillColor(sf::Color::Cyan);
}

void GameOver::render(sf::RenderTarget & target)
{
	target.draw(GOBack);
	target.draw(GO);
	target.draw(ScoreB);
	target.draw(ScoreDis);
	target.draw(MMb);
	target.draw(MM);
}

void GameOver::setScore(int score)
{
	ScoreDis.setString("Your Score \n \t  " + std::to_string(score));
	ScoreDis.setPosition(95.f, 380.f);
}

