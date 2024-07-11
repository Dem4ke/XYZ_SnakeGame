#include "GameStates.h"

namespace SnakeGame {

	GameState::GameState() {}

	// Increase apples counter when apple has been eaten
	void GameState::scoreIncrease(int cost) {
		score_ += cost;
	}

	// Reset apples counter when game has been restarted
	void GameState::resetScore() {
		score_ = 0;
	}

	// Add a new game state in "game states stack"
	void GameState::pushGameState(GameStateType newType) {
		gameStatesStack.push_back(newType);
		gameStateType = gameStatesStack[gameStatesStack.size() - 1];
	}

	// Delete current game state from "game states stack"
	void GameState::popGameState() {
		gameStatesStack.pop_back();
		gameStateType = gameStatesStack[gameStatesStack.size() - 1];
	}

	// Clear "game states stack" and set main menu
	void GameState::restartGameState() {
		gameStatesStack.clear();
		pushGameState(GameStateType::MainMenu);
	}

	int GameState::getScore() const { return score_; }

	int GameState::getPauseTime() const { return afterPauseTime_; }

	GameStateType GameState::getCurrentGameState() const { return gameStateType; }

	DifficultyLevel GameState::getCurrentDiffLvl() const { return diffLvl_; }

	void GameState::setNewDifficulty(DifficultyLevel newDifficulty) {
		diffLvl_ = newDifficulty;
	}
}