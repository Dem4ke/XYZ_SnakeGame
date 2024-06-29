#pragma once

#include "Player.h"

namespace SnakeGame {

	class Rock {
	public:
		Rock(Resources& resources) : resources_(resources) {}

		void init(float size);

		float getSize() const;
		sf::Sprite getSprite() const;

		Position2D position_;

	private:
		float size_ = 0.f;
		sf::Sprite sprite_;
		Resources& resources_;
	};

	void RocksFieldInit(Rock& rock, std::vector<Rock>& fieldOfRocks, float size, int num);
	void RockCollision(std::vector<Rock>& fieldOfRocks, Player& player, Resources& resources, GameState& settings);
	void DrawRocks(std::vector<Rock>& fieldOfRocks, sf::RenderWindow& window);
}
