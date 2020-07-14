#include "PauseMenu.h"

PauseMenu::PauseMenu()
{

	font.loadFromFile("FONTS/IMMORTAL.ttf");

	ContinueButton.setFont(font);
	ContinueButton.setCharacterSize(50);
	ContinueButton.setPosition(90.f - ContinueButton.getGlobalBounds().width / 2.f, 300.f - ContinueButton.getGlobalBounds().height / 2.f);
	ContinueButton.setString("Continue!");

	//pause menu background
	pauseTex.loadFromFile("SPRITES/menu.png");
	pauseBack.setTexture(pauseTex);
}

PauseMenu::~PauseMenu()
{

}

void PauseMenu::update(sf::Vector2f mpos, int& StateID)
{

	if (ContinueButton.getGlobalBounds().contains(mpos))
	{
		ContinueButton.setFillColor(sf::Color(255, 215, 0, 255));
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			StateID = 1;
		}
	}
	else
		ContinueButton.setFillColor(sf::Color::White);
}

void PauseMenu::render(sf::RenderTarget & target)
{
	target.draw(pauseBack);
	target.draw(ContinueButton);
}