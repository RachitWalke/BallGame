#include "PauseMenu.h"

PauseMenu::PauseMenu()
{

	font.loadFromFile("FONTS/comic.ttf");

	ContinueButton.setFont(font);
	ContinueButton.setCharacterSize(50);
	ContinueButton.setPosition(90.f - ContinueButton.getGlobalBounds().width / 2.f, 300.f - ContinueButton.getGlobalBounds().height / 2.f);
	ContinueButton.setString("Continue!");

	//pause menu background
	pauseTex.loadFromFile("SPRITES/menu.png");
	pauseBack.setTexture(pauseTex);

	//UI
	CBtex.loadFromFile("SPRITES/b_5.png");
	CB.setTexture(CBtex);
	CB.setScale(0.46f, 0.3f);
	CB.setPosition(197.f - CB.getGlobalBounds().width / 2.f, 337.f - CB.getGlobalBounds().height / 2.f);
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
			StateID = 2;
		}
	}
	else
		ContinueButton.setFillColor(sf::Color::White);
}

void PauseMenu::render(sf::RenderTarget & target)
{
	target.draw(pauseBack);
	target.draw(CB);
	target.draw(ContinueButton);
}