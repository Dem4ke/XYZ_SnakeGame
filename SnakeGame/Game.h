#pragma once

#include "GameField.h"
#include "Menu.h"
#include "LeaderBoard.h"
#include "PopUp.h"
#include "Player.h"
#include "Apple.h"
#include "Wall.h"
#include "UI.h"

namespace SnakeGame {

	class Game {
	public:
		Game(Resources& resources, sf::RenderWindow& window);

		void initGame();
		void restartGame();
		void updateMenu(sf::Event& event);
		void updateGame(const float& deltaTime);
		void gameOver();
		void drawGame();

	private:
		void initBackground();
	
		sf::RenderWindow& window_;
		Resources& resources_;

		sf::Sprite gameBackSprite_;
		sf::Color gameBackColor_ = sf::Color::Blue;

		Menu mainMenu_;
		Menu difficultyLevelMenu_;
		Menu optionsMenu_;
		Menu exitMenu_;
		Menu pauseMenu_;
		Menu gameOverMenu_;

		LeaderBoard leaderBoard_;

		PopUp gameOverPopUp_;
		PopUp chooseName_;

		UI UI_;

		GameState gameState_;

		GameField gameField_;
	};
}