#include "Game.h"

namespace SnakeGame {

	Game::Game(Resources& resources, sf::RenderWindow& window)
		: resources_(resources), window_(window),
		mainMenu_(resources), difficultyLevelMenu_(resources), 
		optionsMenu_(resources), exitMenu_(resources), 
		pauseMenu_(resources), gameOverMenu_(resources), 
	 /* leaderBoard_(resources),
		UI_(resources),*/ gameField_(resources, gameState_) {}

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
		
		// Initialization of game field, and reset all game objects
		gameField_.init();

		//// Reset apples counter
		gameState_.resetApplesCount();
		//UI_.appleCountUpdate(gameState_);
	}

	// Update menu states, it works only with Event
	void Game::updateMenu(sf::Event& event) {
		switch (gameState_.getCurrentGameState()) {
		case GameStateType::MainMenu: {
			MainMenuMovement(mainMenu_, gameState_, event);
			break;
		}
		case GameStateType::DifficulityLevelChoose: {
			DiffLvlMenuMovement(difficultyLevelMenu_, gameState_, event);
			break;
		}
		case GameStateType::Options: {
			OptionsMenuMovement(optionsMenu_, gameState_, event);
			break;
		}
		case GameStateType::ExitDialog: {
			ExitMenuMovement(exitMenu_, gameState_, event, window_);
			break;
		}
		case GameStateType::Pause: {
			PauseMenuMovement(pauseMenu_, gameState_, event);
			break;
		}
		case GameStateType::LeaderBoard: {
			//		LeaderBoardMovement(leaderBoard_, gameState_, event);
			break;
		}
		case GameStateType::GameOver: {
			GameOverMenuMovement(gameOverMenu_, gameState_, event);
			break;
		}
		}
	}

	// Update only game process 
	void Game::updateGame(const float& deltaTime) {
		if (gameState_.getCurrentGameState() == GameStateType::Game) {

			// Update main game process
			gameField_.update(deltaTime);

			// Pause menu maker
			ExitInPauseMenu(gameState_);
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
