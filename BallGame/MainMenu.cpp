#include "MainMenu.h"
MainMenu::MainMenu()
{

	highscore();

	font.loadFromFile("FONTS/IMMORTAL.ttf");

	//play button
	playButton.setFont(font);
	playButton.setCharacterSize(50);
	playButton.setPosition(130.f - playButton.getGlobalBounds().width / 2.f, 250.f- playButton.getGlobalBounds().height / 2.f);
	playButton.setString("PLAY!");

	//quit button
	quitButton.setFont(font);
	quitButton.setCharacterSize(50);
	quitButton.setPosition(160.f - playButton.getGlobalBounds().width / 2.f, 350.f - playButton.getGlobalBounds().height / 2.f);
	quitButton.setString("QuitGame");

	//handleing highscore
	high.setFont(font);
	high.setCharacterSize(30);
	high.setPosition(165.f - high.getGlobalBounds().width, 0.f);
	high.setFillColor(sf::Color(178, 34, 34, 255));
	high.setOutlineThickness(1.f);
	high.setOutlineColor(sf::Color(0, 255, 127, 255));
	high.setString("HighScore: " + gethigh);

	//menu background
	menuTex.loadFromFile("SPRITES/menu.png");
	menuBack.setTexture(menuTex);
}

MainMenu::~MainMenu()
{

}
void MainMenu::highscore()
{
	obj.open("E:\\Work\\VSProject\\BallGame\\BallGame\\Highscore.txt");
	if (obj.is_open())
	{
		std::getline(obj, gethigh);
		//std::cout << getHS << std::endl;
		obj.close();
	}
	else
	{
		std::cout << "unable to open highscore file" << std::endl;
	}
}
void MainMenu::update(sf::Vector2f mpos, int& StateID)
{


	if (playButton.getGlobalBounds().contains(mpos))
	{
		playButton.setFillColor(sf::Color::Red);
		quitButton.setFillColor(sf::Color::White);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			StateID = 1;
		}
	}
	if (quitButton.getGlobalBounds().contains(mpos))
	{
		playButton.setFillColor(sf::Color::White);
		quitButton.setFillColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			StateID = -1;
		}
	}

}

void MainMenu::render(sf::RenderTarget& target)
{
	target.draw(menuBack);
	target.draw(high);
	target.draw(playButton);
	target.draw(quitButton);
}
