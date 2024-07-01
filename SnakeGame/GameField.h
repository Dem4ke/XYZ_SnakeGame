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
		sf::Sprite getObjectSprite() const;
		bool getInfo() const;
		sf::Sprite sprite_;
	private:
		float height_ = 0.f;
		float width_ = 0.f;


		bool isEmpty_ = true;

		Position2D position_;

	//	sf::Sprite sprite_;
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

	// кажда€ €чейка хранит в себе данные о том что она
	// сейчас отрисовывает и флаг возможности 
	// по€влени€ в ней разных объектов
	// например в зан€той €чейке не может быть
	// отрисовано €блоко
	// но в за€нтой €блоком может быть игрок
	// который это €блоко съест

	

	void DrawGameField(GameField& gameField, sf::RenderWindow& window);
}