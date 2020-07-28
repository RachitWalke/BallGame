#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
	txr.loadFromFile("SPRITES/splash.png");
	sp.setTexture(txr);
	clk.restart().asSeconds();
	alpha = 0;
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::update(sf::Vector2f mpos, int& StateID)
{
	if (alpha >= 255) StateID = 1;

	if (clk.getElapsedTime().asSeconds() > 0.023f)
	{
		alpha++;
		sp.setColor(sf::Color(255, 0, 255, alpha));
		clk.restart().asSeconds();
	}
}

void SplashScreen::render(sf::RenderTarget& target)
{
	target.draw(sp);
}
