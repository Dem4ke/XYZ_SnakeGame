#pragma once

namespace SnakeGame {

	struct Vector2D {
		float x = 0.f;
		float y = 0.f;
	};

	typedef Vector2D Position2D;

	Position2D GetRandomPositionInScreen(float screenWidth, float screenHeight);

	bool IsRectanglesCollide(Position2D rect1Position, Vector2D rect1Size,
		Position2D rect2Position, Vector2D rect2Size);

	bool IsCircusCollide(Position2D circle1Position, float circle1Radius,
		Position2D circle2Position, float circle2Radius);
}