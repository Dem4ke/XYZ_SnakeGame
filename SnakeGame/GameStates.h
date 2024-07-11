#pragma once

#include <vector>

namespace SnakeGame {

	enum class DifficultyLevel {
		None = 0,
		Easy,
		HarderThanEasy,
		Medium,
		LessThanHard,
		Hard,
	};

	enum class GameStateType {
		None = 0,
		MainMenu,
		GameReset,
		Game,
		Pause,
		GameOver,
		LeaderBoard,
		DifficulityLevelChoose,
		Options,
		ExitDialog,
	};

	// Settings 
	class GameState {
	public: 
		GameState();

		void scoreIncrease(int cost);
		void resetScore();
		
		void pushGameState(GameStateType newType);
		void popGameState();
		void restartGameState();

		int getScore() const;
		GameStateType getCurrentGameState() const;

		// Difficulty 
		DifficultyLevel getCurrentDiffLvl() const;
		void setNewDifficulty(DifficultyLevel newDifficulty);

	private:
		DifficultyLevel diffLvl_ = DifficultyLevel::Easy;

		int score_ = 0;

		GameStateType gameStateType = GameStateType::None;
		std::vector<GameStateType> gameStatesStack;
	};
}
