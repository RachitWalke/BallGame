#include "PauseMenu.h"

PauseMenu::PauseMenu()
{

	font.loadFromFile("FONTS/IMMORTAL.ttf");

	pauseButton.setFont(font);
	pauseButton.setCharacterSize(30);
	pauseButton.setFillColor(sf::Color(255,215,0,255));
	pauseButton.setPosition(190.f - pauseButton.getGlobalBounds().width / 2.f, 0.f);
	pauseButton.setString("II");

	ContinueButton.setFont(font);
	ContinueButton.setCharacterSize(50);
	ContinueButton.setPosition(90.f - ContinueButton.getGlobalBounds().width / 2.f, 300.f - ContinueButton.getGlobalBounds().height / 2.f);
	ContinueButton.setString("Continue!");

}

PauseMenu::~PauseMenu()
{

}

const bool PauseMenu::getPauseGame() const
{
	return pauseGame;
}

void PauseMenu::updatePauseMenu(sf::RenderWindow & window)
{
	auto pos = sf::Mouse::getPosition(window);
	posView = window.mapPixelToCoords(pos);

	if (pauseButton.getGlobalBounds().contains(posView))
	{
		pauseButton.setFillColor(sf::Color::Red);
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			pauseGame = true;
			
		}
	}
	else
		pauseButton.setFillColor(sf::Color(255, 215, 0, 255));
	if (ContinueButton.getGlobalBounds().contains(posView))
	{
		ContinueButton.setFillColor(sf::Color(255, 215, 0, 255));
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			pauseGame = false;
		}
	}
	else
		ContinueButton.setFillColor(sf::Color::White);
}

void PauseMenu::drawPause(sf::RenderWindow & window)
{
	window.draw(pauseButton);
}

void PauseMenu::drawContinue(sf::RenderWindow & window)
{
	window.draw(ContinueButton);
}
