#include "MainMenu.h"

MainMenu::MainMenu()
{

	font.loadFromFile("FONTS/IMMORTAL.ttf");

	playButton.setFont(font);
	playButton.setCharacterSize(50);
	playButton.setPosition(130.f - playButton.getGlobalBounds().width / 2.f, 250.f- playButton.getGlobalBounds().height / 2.f);
	playButton.setString("PLAY!");

	quitButton.setFont(font);
	quitButton.setCharacterSize(50);
	quitButton.setPosition(160.f - playButton.getGlobalBounds().width / 2.f, 350.f - playButton.getGlobalBounds().height / 2.f);
	quitButton.setString("QuitGame");

}

MainMenu::~MainMenu()
{

}

const bool MainMenu::getPlayGame() const
{
	return playgame;
}

void MainMenu::updateMenu(sf::RenderWindow& window)
{

	auto pos = sf::Mouse::getPosition(window);
	posView = window.mapPixelToCoords(pos);

	if (playButton.getGlobalBounds().contains(posView))
	{
		playButton.setFillColor(sf::Color::Red);
		quitButton.setFillColor(sf::Color::White);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			playgame = true;
		}
	}
	if (quitButton.getGlobalBounds().contains(posView))
	{
		playButton.setFillColor(sf::Color::White);
		quitButton.setFillColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			window.close();
		}
	}

}

void MainMenu::draw(sf::RenderWindow& window)
{
	window.draw(playButton);
	window.draw(quitButton);
}
