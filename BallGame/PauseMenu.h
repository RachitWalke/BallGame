#pragma once

#include<SFML\Graphics.hpp>


class PauseMenu
{

private:
	   //variables;
	bool pauseGame = false;
	sf::Vector2f posView;
	sf::Font font;
	sf::Text pauseButton;
	sf::Text ContinueButton;

public:

	//cons and des
	PauseMenu();
	~PauseMenu();

	//member funcs
	const bool getPauseGame() const;
	void updatePauseMenu(sf::RenderWindow& window);
	void drawPause(sf::RenderWindow& window);
	void drawContinue(sf::RenderWindow& window);
};

