#include "Game.h"

namespace SnakeGame {

	Game::Game(Resources& resources, sf::RenderWindow& window)
		: resources_(resources), window_(window),
		mainMenu_(resources), difficultyLevelMenu_(resources), 
		optionsMenu_(resources), exitMenu_(resources), 
		pauseMenu_(resources), gameOverMenu_(resources), 
		player_(resources), apple_(resources),/*
		rock_(resources), leaderBoard_(resources),
		UI_(resources),*/ gameField_(resources, player_, apple_) {}

	void Game::initGame() {
		std::vector<std::string> mainButtons = { "Play game", "Difficulity level", "Leader board", "Options", "Exit" };
		std::vector<std::string> dufficulityLevelButtons = { "Easy", "Harder than Easy", "Medium", "Pussy hard", "Die hard" };
		std::vector<std::string> optionsButtons = { "Music: On", "Sounds: On" };
		std::vector<std::string> exitButtons = { "Yes", "No" };
		std::vector<std::string> pauseButtons = { "Yes", "No" };
		std::vector<std::string> gameOverButtons = { "\n\n\n\n\n\n\n\n\n\nExit" };

		// Menu initialization (Name of menu, vector of buttons, size of buttons, color of buttons, id of menu)
		// Name of menu will be in 1.5 bigger, id of menu needs for choose of background
		// id: 0 - empty background, 1 or any other - main background
		mainMenu_.init("Snake Game", mainButtons, 40.f, sf::Color::White, 1);
		difficultyLevelMenu_.init("Difficulity level", dufficulityLevelButtons, 40.f, sf::Color::White, 1);
		optionsMenu_.init("Options", optionsButtons, 40.f, sf::Color::White, 1);
		exitMenu_.init("Do you want to exit?", exitButtons, 40.f, sf::Color::White, 1);
		pauseMenu_.init("Do you want to exit\n\tin main menu?\n", pauseButtons, 40.f, sf::Color::White, 0);
		gameOverMenu_.init("Game Over\n\n", gameOverButtons, 40.f, sf::Color::White, 1);

		// Leader board initialization (Name of menu, size of names, Settings class object)
		//leaderBoard_.init("Leader Board", 40.f, gameState_);

		//// User interface initialization (size of a text elements)
		//UI_.init(20.f);
		
		// Initialization of a background music and start to play it
		SetMusicVolume(resources_, 5.f);
		PlayBackMusic(resources_);

		// Initialization of start sounds volume
		SetSoundsVolume(resources_, 5.f);

		// Initialization of background of the game
		initBackground();

		restartGame();
	}

	void Game::restartGame() {
		// Reset game state 
		gameState_.restartGameState();
		
		// Player initialization (size of player, speed)
		//player_.init(30.f, 100.f);

		//// Apple initialization (Apple class object, array of objects, size of apple, number of apples on the field)
		//ApplesFieldInit(apple_, fieldOfApples_, 20.f, gameState_.getNumOfApples());

		//// Reset apples counter
		//gameState_.resetApplesCount();
		//UI_.appleCountUpdate(gameState_);

		// Rock initialization (Rock class object, array of objects, size of rock, number of rocks on the field)
		//RocksFieldInit(rock_, fieldOfRocks_, 30.f, gameState_.numOfRocks);
	}

	// Update menu states, it works only with Event
	void Game::updateMenu(sf::Event& event) {
		
		if (gameState_.getCurrentGameState() == GameStateType::MainMenu) {
			MainMenuMovement(mainMenu_, gameState_, event);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::DifficulityLevelChoose) {
			DiffLvlMenuMovement(difficultyLevelMenu_, gameState_, event);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::Options) {
			OptionsMenuMovement(optionsMenu_, gameState_, event);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::ExitDialog) {
			ExitMenuMovement(exitMenu_, gameState_, event, window_);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::Pause) {
			PauseMenuMovement(pauseMenu_, gameState_, event);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::LeaderBoard) {
	//		LeaderBoardMovement(leaderBoard_, gameState_, event);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::GameOver) {
			GameOverMenuMovement(gameOverMenu_, gameState_, event);
		}
	}

	// Update only game process 
	void Game::updateGame(const float& deltaTime) {
		if (gameState_.getCurrentGameState() == GameStateType::Game) {

			//// Player movement
			//PlayerMove(player_, deltaTime);

			//// Window collision
			//OutOfWindow(player_, resources_, gameState_);

			//// Collision with rocks
			//RockCollision(fieldOfRocks_, player_, resources_, gameState_);

			// Pause menu maker
			ExitInPauseMenu(gameState_);

			// Differents versions of collision with apples
	/*		if ((gameState_.gameSettings & GameOptions::isApplesInfinite) &&
				!(gameState_.gameSettings & GameOptions::isPlayerAccelerated)) {

				InfApplesWithNoAcc(fieldOfApples_, player_, resources_, gameState_, UI_);
			}
			else if ((gameState_.gameSettings & GameOptions::isApplesInfinite) && 
					(gameState_.gameSettings & GameOptions::isPlayerAccelerated)) {

				InfApplesWithAcc(fieldOfApples_, player_, resources_, gameState_, UI_);
			}
			else if (!(gameState_.gameSettings & GameOptions::isApplesInfinite) && 
					!(gameState_.gameSettings & GameOptions::isPlayerAccelerated)) {

				LimApplesWithNoAcc(fieldOfApples_, player_, resources_, gameState_, UI_);
			}
			else if (!(gameState_.gameSettings & GameOptions::isApplesInfinite) && 
					(gameState_.gameSettings & GameOptions::isPlayerAccelerated)) {

				LimApplesWithAcc(fieldOfApples_, player_, resources_, gameState_, UI_);
			}*/
		}
	}

	void Game::gameOver(const float& deltaTime) {
		/*if (gameState_.getCurrentGameState() == GameStateType::GameOver) {
			leaderBoard_.sortTable(gameState_);
		
		else */ if (gameState_.getCurrentGameState() == GameStateType::GameReset) {
			restartGame();
		}
	}

	void Game::drawGame() {
		if (gameState_.getCurrentGameState() == GameStateType::MainMenu) {
			DrawMenu(mainMenu_, window_);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::DifficulityLevelChoose) {
			DrawMenu(difficultyLevelMenu_, window_);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::Options) {
			DrawMenu(optionsMenu_, window_);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::ExitDialog) {
			DrawMenu(exitMenu_, window_);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::Pause) {
			DrawMenu(pauseMenu_, window_);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::GameOver) {
			DrawMenu(gameOverMenu_, window_);
	//		DrawLeaderBoard(leaderBoard_, window_);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::LeaderBoard) {
	//		DrawLeaderBoard(leaderBoard_, window_);
		}
		else if (gameState_.getCurrentGameState() == GameStateType::Game) {
		//	DrawUI(UI_, window_);
			window_.draw(gameBackSprite_);
			DrawGameField(gameField_, window_);
		}
	}

	void Game::initBackground() {
		// Initialization of background of the game
		gameBackSprite_.setTexture(resources_.gameBackground);
		SetSpriteSize(gameBackSprite_, resources_.getWindowWidth(), resources_.getWindowHeight());
		gameBackSprite_.setColor(gameBackColor_);
	}
}
