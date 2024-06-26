#pragma once

#include "Resources.h"
#include "Settings.h"
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
		void init(float playerSize, float playerSpeed);
		void moveRight();
		void moveLeft();
		void moveUp();
		void moveDown();
		void speedUp();

		void rotateSprite(float rotateDegree);
		void setNormalPlayerSprite();
		void setMirrorPlayerSprite();
		void setSpritePosition(float x, float y);

		float getSize() const;
		float getSpeed() const;
		sf::RectangleShape getBackground() const;
		sf::Sprite getSprite() const;
		PlayerDirection getDirection() const;

		Position2D position_;

	private:
		float size_ = 0.f;
		float speed_ = 0.f;
		float acceleration_ = 20.f;

		PlayerDirection direction_ = PlayerDirection::Right;
		sf::Sprite sprite_;
		sf::RectangleShape background_;

		Resources& resources_;
	};

	void PlayerMove(Player& player, const float& deltaTime);
	void OutOfWindow(Player& player, Resources& resources, GameStates& settings);
	void DrawPlayer(Player& player, sf::RenderWindow& window);
}
