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
		Player(Resources& resources) : resources_(resources) {}
		void init(float speed);

		void moveRight();
		void moveLeft();
		void moveUp();
		void moveDown();

		void setPositionOnField(int positionFromField);

		int getPositionOnField() const;
		float getSize() const;
		float getSpeed() const;
		PlayerDirection getDirection() const;

	private:
		int positionOnField_ = 0;
		int size_ = 0;
		float speed_ = 0.f;

		PlayerDirection direction_ = PlayerDirection::Right;

		Resources& resources_;
	};
}
