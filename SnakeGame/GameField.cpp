#include "GameField.h"

namespace SnakeGame {

	// CELL

	CellOfField::CellOfField(float height, float width) :
		height_(height), width_(width) {}

	// Set sprite's position
	void CellOfField::setSpritePosition(float x, float y) {
		sprite_.setPosition(x, y);
	}

	void CellOfField::rotateSprite(float rotateDegree) {
		sprite_.setRotation(rotateDegree);
	}
	// Set sprite's texute, size and origin
	void CellOfField::setObject(sf::Texture& texture) {
		sprite_.setTexture(texture);
		SetSpriteSize(sprite_, height_, width_);
		SetSpriteRelativeOrigin(sprite_, 0.5f, 0.5f);
	}

	sf::Sprite CellOfField::getObjectSprite() const {
		return sprite_;
	}

	// GAME FIELD

	GameField::GameField(Resources& resources, GameState& gameState) :
		resources_(resources), player_(resources),
		apple_(resources), wall_(resources),
		gameState_(gameState) {

		init();
		setPerimeterCellSprite(); // set all walls for perimeter of field	
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

			// Sprite position is in center of a cell
			cell.setSpritePosition(countOfCols * width + 0.5f * width, 
								countOfRows * height + 0.5f * height);
			field_.push_back(cell);

			++countOfCols;
			if (countOfCols == cols) {
				countOfCols = 0;
				++countOfRows;
			}

			// Initialiazation of the player
			switch (gameState_.getCurrentDiffLvl()) {
			case DifficultyLevel::Easy: {
				player_.init(1.f);
				break;
			}
			case DifficultyLevel::HarderThanEasy: {
				player_.init(2.f);
				break;
			}
			case DifficultyLevel::Medium: {
				player_.init(3.f);
				break;
			}
			case DifficultyLevel::LessThanHard: {
				player_.init(4.f);
				break;
			}
			case DifficultyLevel::Hard: {
				player_.init(5.f);
				break;
			}
			}
		}
	}

	void GameField::update(const float& deltaTime) {
		// Change snake's head direction
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player_.moveRight();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player_.moveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player_.moveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player_.moveDown();
		}

		// Change position of snake's head sprite 
		switch (player_.getDirection()) {
		case PlayerDirection::Up: {
			field_[].setObject(resources_.snakeHeadTexture);
			field_[620].rotateSprite(270.f);
			break;
		}
		case PlayerDirection::Down: {
			field_[620].setObject(resources_.snakeHeadTexture);
			field_[620].rotateSprite(90.f);
			break;
		}
		case PlayerDirection::Right: {
			field_[620].setObject(resources_.snakeHeadTexture);
			field_[620].rotateSprite(0.f);
			break;
		}
		case PlayerDirection::Left: {
			field_[620].setObject(resources_.snakeHeadTexture);
			field_[620].rotateSprite(180.f);
			break;
		}
		}
	}

	int GameField::getFieldSize() const { return cols * rows; }

	sf::Sprite GameField::getSprite(int index) const {
		return field_[index].getObjectSprite();
	}

	// PRIVATE TOOLS

	// Set sprites on perimeter
	void GameField::setPerimeterCellSprite() {
		// Make a counters to count cells
		int countOfCols = 0;
		int countOfRows = 0;

		// Set walls around field
		for (int i = 0, end = getFieldSize(); i < end; ++i, ++countOfCols) {
			if (countOfCols == cols) {
				countOfCols = 0;
				++countOfRows;
			}

			if (countOfCols == 0) {
				field_[i].setObject(resources_.wallTexture);
				field_[i].rotateSprite(90.f);
			}
			else if (countOfCols == cols - 1) {
				field_[i].setObject(resources_.wallTexture);
				field_[i].rotateSprite(270.f);
			}
			else if (countOfRows == 0) {
				field_[i].setObject(resources_.wallTexture);
				field_[i].rotateSprite(180.f);
			}
			else if (countOfRows == rows - 1) {
				field_[i].setObject(resources_.wallTexture);
			}
		}
	}

	void GameField::setPlayerCellSprite() {

	}

	// FUNCTIONS

	void DrawGameField(GameField& gameField, sf::RenderWindow& window) {
		for (int i = 0, end = gameField.getFieldSize(); i < end; ++i) {
			window.draw(gameField.getSprite(i));
		}
	}
}