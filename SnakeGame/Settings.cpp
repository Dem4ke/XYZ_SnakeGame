#include "Settings.h"

namespace SnakeGame {

	GameStates::GameStates() {}

	// Increase apples counter when apple has been eaten
	void GameStates::appleIncrease() {
		++eatenApples_;
	}

	// Reset apples counter when game has been restarted
	void GameStates::resetApplesCount() {
		eatenApples_ = 0;
	}

	// Add a new game state in "game states stack"
	void GameStates::pushGameState(GameStateType newType) {
		gameStatesStack.push_back(newType);
		gameStateType = gameStatesStack[gameStatesStack.size() - 1];
	}

	// Delete current game state from "game states stack"
	void GameStates::popGameState() {
		gameStatesStack.pop_back();
		gameStateType = gameStatesStack[gameStatesStack.size() - 1];
	}

	// Clear "game states stack" and set main menu
	void GameStates::restartGameState() {
		gameStatesStack.clear();
		pushGameState(GameStateType::MainMenu);
	}

	int GameStates::getNumOfApples() const { return numOfApples_; }

	GameStateType GameStates::getCurrentGameState() const { return gameStateType; }
}