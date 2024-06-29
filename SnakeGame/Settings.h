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
	class GameStates {
	public: 
		GameStates();

		void appleIncrease();
		void resetApplesCount();
		
		void pushGameState(GameStateType newType);
		void popGameState();
		void restartGameState();

		int getNumOfApples() const;
		GameStateType getCurrentGameState() const;

		DifficultyLevel getCurrentDiffLvl() const;

	private:
		DifficultyLevel diffLvl_ = DifficultyLevel::Easy;

		int eatenApples_ = 0;
		int numOfApples_ = 20;

		GameStateType gameStateType = GameStateType::None;
		std::vector<GameStateType> gameStatesStack;
	};

	class DifficultyOfGame {

	};
}
