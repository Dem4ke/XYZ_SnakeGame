#include "GameField.h"

namespace SnakeGame {

	// CELL

	CellOfField::CellOfField(float height, float width) :
		height_(height), width_(width) {}

	void CellOfField::setSpritePosition(float x, float y) {
		sprite_.setPosition(x, y);
	}

	void CellOfField::setObject(sf::Texture& texture) {
		sprite_.setTexture(texture);
		SetSpriteSize(sprite_, height_, width_);
	}

	sf::Sprite CellOfField::getObjectSprite() const {
		return sprite_;
	}

	// GAME FIELD

	GameField::GameField(Resources& resources, Player& player, Apple& apple) : 
		resources_(resources), player_(player), apple_(apple) {

		init();
		setPerimeterCellSprite(); // set all walls for perimetr of field		
	}

	// Initialization of game field
	// Split playable screen on cells and put them in vector	
	void GameField::init() {
		// reserve vector capacity
		int end = rows * cols;
		field_.reserve(end);

		// get height and width of any cell
		float height = resources_.getWindowHeight() / rows;
		float width = resources_.getWindowWidth() / cols;

		// Make a counters to count created cells
		int countOfCols = 0;
		int countOfRows = 0;

		// Initialization of all cells 
		for (int i = 0; i < end; ++i) {
			CellOfField cell(height, width);
			
			// must count cols and rows to dont go out of window borders
			// because of screen is matrix of cells
			// cols counter have to be less than cols
			// rows counter have to be less than rows

			cell.setSpritePosition(countOfCols * width, countOfRows * height);
			field_.push_back(cell);

			++countOfCols;
			if (countOfCols == cols) {
				countOfCols = 0;
				++countOfRows;
			}
		}
	}

	// Set sprite in cell based on needs
	void GameField::setPerimeterCellSprite() {
		// Make a counters to count created cells
		int countOfCols = 0;
		int countOfRows = 0;

		// Set walls around field
		for (int i = 0, end = getFieldSize(); i < end; ++i) {
			if (countOfCols != cols - 1 && countOfRows == 0) {
				field_[i].setObject(resources_.wallTexture);
			} 
			else if (countOfCols == cols - 1) {
				field_[i].setObject(resources_.appleTexture);
				countOfCols = 0;
				++countOfRows;	
			}
			else if (countOfCols == 0) {
			//	field_[i].setObject(resources_.wallTexture);
			}
			++countOfCols;
		}
	}

	int GameField::getFieldSize() const { return cols * rows; }

	sf::Sprite GameField::getSprite(int index) const {
		sf::Sprite sprite = field_[index].getObjectSprite();
		return sprite;
	}

	// FUNCTIONS

	void DrawGameField(GameField& gameField, sf::RenderWindow& window) {
		for (int i = 0, end = gameField.getFieldSize(); i < end; ++i) {
			window.draw(gameField.getSprite(i));
		}
	}
}