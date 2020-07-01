#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>

class MainMenu
{

	private:
		//variables
		bool playgame = false;
		sf::Vector2f posView;
		sf::Font font;
		sf::Text playButton;
		sf::Text quitButton;

	public:

		//cons and des
		MainMenu();
		~MainMenu();

		//member funcs
		const bool getPlayGame() const;
		void updateMenu(sf::RenderWindow& window);
		void draw(sf::RenderWindow& window);

};

