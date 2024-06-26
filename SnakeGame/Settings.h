#pragma once

#include <vector>

namespace SnakeGame {

	enum GameOptions {
		isApplesInfinite = 1 << 0,
		isPlayerAccelerated = 1 << 1,
	};

	enum class GameStateType {
		None = 0,
		MainMenu,
		GameReset,
		Game,
		Pause,
		GameOver,
		LeaderBoard,
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

	private:
		char gameSettings_ = 3;

		int eatenApples_ = 0;
		int numOfApples_ = 20;

		GameStateType gameStateType = GameStateType::None;
		std::vector<GameStateType> gameStatesStack;
	};
}
