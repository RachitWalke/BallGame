#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
#include"state.h"

class MainMenu : public state
{

	private:
		//variables
		sf::Font font;
		sf::Text playButton;
		sf::Text quitButton;
		sf::Texture menuTex;
		sf::Sprite menuBack;
		sf::Text high;
		std::string gethigh;
		std::fstream obj;

	public:

		//cons and des
		MainMenu();
		~MainMenu();

		//member funcs
		void  highscore();
		void update(sf::Vector2f mpos, int& StateID) override;
		void render(sf::RenderTarget& target) override;

};

