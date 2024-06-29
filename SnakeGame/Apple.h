#pragma once

#include "Player.h"
#include "UI.h"

namespace SnakeGame {

	class Apple {
	public:
		Apple(Resources& resources) : resources_(resources) {}

		void init(float size);
		void appleEaten();
		void getRandomPosition();

		float getSize() const;
		bool isAppleEaten() const;
		sf::Sprite getSprite() const;

		Position2D position_;

	private:
		float size_ = 0.f;
		bool isAppleEaten_ = false;
		sf::Sprite sprite_;
		Resources& resources_;
	};

	void ApplesFieldInit(Apple& apple, std::vector<Apple>& fieldOfApples, float size, int num);
	void InfApplesWithNoAcc(std::vector<Apple>& fieldOfApples, Player& player, Resources& resources, GameState& settings, UI& UI);
	void InfApplesWithAcc(std::vector<Apple>& fieldOfApples, Player& player, Resources& resources, GameState& settings, UI& UI);
	void LimApplesWithNoAcc(std::vector<Apple>& fieldOfApples, Player& player, Resources& resources, GameState& settings, UI& UI);
	void LimApplesWithAcc(std::vector<Apple>& fieldOfApples, Player& player, Resources& resources, GameState& settings, UI& UI);
	void DrawApples(std::vector<Apple>& fieldOfApples, sf::RenderWindow& window);
}
