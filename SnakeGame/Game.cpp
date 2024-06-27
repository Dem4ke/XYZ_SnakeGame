#include "Game.h"

namespace SnakeGame {

	Game::Game(Resources& resources, sf::RenderWindow& window)
		: resources_(resources), window_(window), mainMenu_(resources),
		optionsMenu_(resources), exitMenu_(resources), pauseMenu_(resources),
		gameOverMenu_(resources)/*, player_(resources), apple_(resources),
		rock_(resources), leaderBoard_(resources), UI_(resources)*/ {}

	void Game::initGame() {
		std::vector<std::string> mainButtons = { "Play game", "Leader board", "Options", "Exit" };
		std::vector<std::string> optionsButtons = { "Acceleration: On", "Infinite apples: On" };
		std::vector<std::string> exitButtons = { "Yes", "No" };
		std::vector<std::string> pauseButtons = { "Yes", "No" };
		std::vector<std::string> gameOverButtons = { "\n\n\n\n\n\n\n\n\n\nExit" };

		// Menu initialization (Name of menu, vector of buttons, size of buttons, color of buttons, <id of menu>)
		// Name of menu will be in 1.5 bigger, id of menu needs for background (black background by default)
		// id: 1 - main; 2 - options; 3 - exit, 4 - pause; 5 - game over
		mainMenu_.init("Snake Game", mainButtons, 40.f, sf::Color::White, 1);
		optionsMenu_.init("Options", optionsButtons, 40.f, sf::Color::White, 2);
		exitMenu_.init("Do you want to exit?", exitButtons, 40.f, sf::Color::White, 3);
		pauseMenu_.init("Do you want to exit\n\tin main menu?\n", pauseButtons, 40.f, sf::Color::White, 1);
		gameOverMenu_.init("Game Over\n\n", gameOverButtons, 40.f, sf::Color::White, 1);

		//// Leader board initialization (Name of menu, size of names, Settings class object)
		//leaderBoard_.init("Leader Board", 40.f, gameStates_);

		//// User interface initialization (size of button)
		//UI_.init(20.f);

		restartGame();
	}

	void Game::restartGame() {
		// Reset game state 
		gameStates_.restartGameState();

		// Player initialization (size of player, speed)
		//player_.init(30.f, 100.f);

		//// Apple initialization (Apple class object, array of objects, size of apple, number of apples on the field)
		//ApplesFieldInit(apple_, fieldOfApples_, 20.f, gameStates_.getNumOfApples());

		//// Reset apples counter
		//gameStates_.resetApplesCount();
		//UI_.appleCountUpdate(gameStates_);

		// Rock initialization (Rock class object, array of objects, size of rock, number of rocks on the field)
		//RocksFieldInit(rock_, fieldOfRocks_, 30.f, gameStates_.numOfRocks);
	}

	// Update menu states, it works only with Event
	void Game::updateMenu(sf::Event& event) {
		if (gameStates_.getCurrentGameState() == GameStateType::MainMenu) {
			MainMenuMovement(mainMenu_, gameStates_, event);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::Options) {
			OptionsMenuMovement(optionsMenu_, gameStates_, event);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::ExitDialog) {
			ExitMenuMovement(exitMenu_, gameStates_, event, window_);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::Pause) {
			PauseMenuMovement(pauseMenu_, gameStates_, event);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::LeaderBoard) {
	//		LeaderBoardMovement(leaderBoard_, gameStates_, event);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::GameOver) {
			GameOverMenuMovement(gameOverMenu_, gameStates_, event);
		}
	}

	// Update only game process 
	void Game::updateGame(const float& deltaTime) {
		if (gameStates_.getCurrentGameState() == GameStateType::Game) {

			//// Player movement
			//PlayerMove(player_, deltaTime);

			//// Window collision
			//OutOfWindow(player_, resources_, gameStates_);

			//// Collision with rocks
			//RockCollision(fieldOfRocks_, player_, resources_, gameStates_);

			//// Pause menu maker
			//ExitInPauseMenu(gameStates_);

			// Differents versions of collision with apples
	/*		if ((gameStates_.gameSettings & GameOptions::isApplesInfinite) &&
				!(gameStates_.gameSettings & GameOptions::isPlayerAccelerated)) {

				InfApplesWithNoAcc(fieldOfApples_, player_, resources_, gameStates_, UI_);
			}
			else if ((gameStates_.gameSettings & GameOptions::isApplesInfinite) && 
					(gameStates_.gameSettings & GameOptions::isPlayerAccelerated)) {

				InfApplesWithAcc(fieldOfApples_, player_, resources_, gameStates_, UI_);
			}
			else if (!(gameStates_.gameSettings & GameOptions::isApplesInfinite) && 
					!(gameStates_.gameSettings & GameOptions::isPlayerAccelerated)) {

				LimApplesWithNoAcc(fieldOfApples_, player_, resources_, gameStates_, UI_);
			}
			else if (!(gameStates_.gameSettings & GameOptions::isApplesInfinite) && 
					(gameStates_.gameSettings & GameOptions::isPlayerAccelerated)) {

				LimApplesWithAcc(fieldOfApples_, player_, resources_, gameStates_, UI_);
			}*/
		}
	}

	void Game::gameOver(const float& deltaTime) {
		/*if (gameStates_.getCurrentGameState() == GameStateType::GameOver) {
			leaderBoard_.sortTable(gameStates_);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::GameReset) {
			restartGame();
		}*/
	}

	void Game::drawGame() {
		if (gameStates_.getCurrentGameState() == GameStateType::MainMenu) {
			DrawMenu(mainMenu_, window_);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::Options) {
			DrawMenu(optionsMenu_, window_);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::ExitDialog) {
			DrawMenu(exitMenu_, window_);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::Pause) {
			DrawMenu(pauseMenu_, window_);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::GameOver) {
			DrawMenu(gameOverMenu_, window_);
	//		DrawLeaderBoard(leaderBoard_, window_);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::LeaderBoard) {
	//		DrawLeaderBoard(leaderBoard_, window_);
		}
		else if (gameStates_.getCurrentGameState() == GameStateType::Game) {
	/*		DrawPlayer(player_, window_);
			DrawRocks(fieldOfRocks_, window_);
			DrawApples(fieldOfApples_, window_);
			DrawUI(UI_, window_);*/
		}
	}
}