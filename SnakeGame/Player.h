#pragma once

#include "Resources.h"
#include "GameStates.h"
#include "Engine.h"

namespace SnakeGame {

	enum class PlayerDirection : int {
		Right = 0,
		Up,
		Left,
		Down
	};

	class Player {
	public:
		Player();
		void init(int speed = 1, int size = 4, int position = 620);

		void moveRight();
		void moveLeft();
		void moveUp();
		void moveDown();
		
		void sizeIncrease();
		void setPositionOnField(int newPosition);

		int getPositionOnField(int index) const;
		int getSize() const;
		int getSpeed() const;
		PlayerDirection getDirection() const;

	private:
		int size_ = 0;
		int speed_ = 0;
		int positionBuffer_ = 0;
		std::vector<int> positionOnField_;

		PlayerDirection direction_ = PlayerDirection::Right;
	};
}
