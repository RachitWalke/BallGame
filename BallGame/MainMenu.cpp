#include "MainMenu.h"
MainMenu::MainMenu()
{

	highscore();

	font.loadFromFile("FONTS/comic.ttf");

	//play button
	playButton.setFont(font);
	playButton.setCharacterSize(50);
	playButton.setPosition(130.f - playButton.getGlobalBounds().width / 2.f, 230.f- playButton.getGlobalBounds().height / 2.f);
	playButton.setString("PLAY!");
	playButton.setFillColor(sf::Color(138, 43, 226, 255));

	//quit button
	quitButton.setFont(font);
	quitButton.setCharacterSize(50);
	quitButton.setPosition(150.f - playButton.getGlobalBounds().width / 2.f, 380.f - playButton.getGlobalBounds().height / 2.f);
	quitButton.setString("QuitGame");
	quitButton.setFillColor(sf::Color(138, 43, 226, 255));

	//handleing highscore
	high.setFont(font);
	high.setCharacterSize(30);
	high.setPosition(165.f - high.getGlobalBounds().width, 0.f);
	high.setFillColor(sf::Color(153, 50, 204, 255));
	high.setOutlineThickness(1.5f);
	high.setOutlineColor(sf::Color(0, 255, 127, 255));
	high.setString("HighScore: " + gethigh);

	//menu background
	menuTex.loadFromFile("SPRITES/menu.png");
	menuBack.setTexture(menuTex);

	//Handling UI
	PBtex.loadFromFile("SPRITES/b_2.png");
	QBtex.loadFromFile("SPRITES/b_1.png");

	PB.setTexture(PBtex);
	QB.setTexture(QBtex);

	PB.setScale(0.31f, 0.26f);
	QB.setScale(0.38f, 0.26f);

	PB.setPosition(197.f - PB.getGlobalBounds().width / 2.f, 265.f - PB.getGlobalBounds().height / 2.f);
	QB.setPosition(110.f - playButton.getGlobalBounds().width / 2.f, 370.f - playButton.getGlobalBounds().height / 2.f);
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
		playButton.setFillColor(sf::Color(255, 69, 0, 255));
		quitButton.setFillColor(sf::Color(138, 43, 226, 255));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			StateID = 1;
		}
	}
	if (quitButton.getGlobalBounds().contains(mpos))
	{
		playButton.setFillColor(sf::Color(138, 43, 226, 255));
		quitButton.setFillColor(sf::Color(255, 69, 0, 255));
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
	target.draw(PB);
	target.draw(QB);
	target.draw(playButton);
	target.draw(quitButton);
}
