#pragma once

#include "Engine.h"
#include "Resources.h"
#include "Player.h"
#include "Apple.h"
#include "Wall.h"

namespace SnakeGame {

	class CellOfField {
	public:
		CellOfField(float height, float width);

		void setSpritePosition(float x, float y);

		void setObject(sf::Texture& texture);
		void rotateSprite(float rotateDegree);

		sf::Sprite getObjectSprite() const;
		bool getInfo() const;
		
	private:
		float height_ = 0.f;
		float width_ = 0.f;

		bool isEmpty_ = true;

		sf::Sprite sprite_;
	};

	class GameField {
	public:
		GameField(Resources& resources, Player& player, Apple& apple);

		void init();
		void setPerimeterCellSprite();

		int getFieldSize() const;
		sf::Sprite getSprite(int index) const;

	private:
		int cols = 40;
		int rows = 30;

		std::vector<CellOfField> field_;

		Resources& resources_;
		Player& player_;
		Apple& apple_;
		//Wall& wall;
	};

	void DrawGameField(GameField& gameField, sf::RenderWindow& window);
}