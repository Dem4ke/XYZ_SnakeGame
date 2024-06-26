#include "Apple.h"

namespace SnakeGame {

	// ROCK INITIALIZATION

	void Apple::init(float size) {
		size_ = size;
		getRandomPosition();

		sprite_.setTexture(resources_.appleTexture);

		SetSpriteSize(sprite_, size_, size_);
		SetSpriteRelativeOrigin(sprite_, 0.5f, 0.5f);
	}

	void Apple::appleEaten() { isAppleEaten_ = true; }

	void Apple::getRandomPosition() {
		position_ = GetRandomPositionInScreen(resources_.getWindowWidth(), resources_.getWindowHeight());
		sprite_.setPosition(position_.x, position_.y);
	}

	float Apple::getSize() const { return size_; }

	bool Apple::isAppleEaten() const { return isAppleEaten_; }

	sf::Sprite Apple::getSprite() const { return sprite_; }

	// FUNCTIONS

	// Initialization of array of apple, take one Apple class object and make array of them
	void ApplesFieldInit(Apple& apple, std::vector<Apple>& fieldOfApples, float size, int num) {
		// Clear field
		fieldOfApples.clear();
		// Init new field
		for (int i = 0; i < num; ++i) {
			apple.init(size);
			fieldOfApples.push_back(apple);
		}
	}

	// Differents versions of collision with apples

	// Infinite apples and player without acceleration
	void InfApplesWithNoAcc(std::vector<Apple>& fieldOfApples, Player& player, Resources& resources, GameStates& settings, UI& UI) {
		for (auto& apple : fieldOfApples) {
			if (IsCircusCollide(player.position_, player.getSize(), apple.position_, apple.getSize())) {
				settings.appleIncrease();
				UI.appleCountUpdate(settings);

				apple.getRandomPosition();
				AppleEatenSound(resources);
			}
		}
	}

	// Infinite apples and player with acceleration
	void InfApplesWithAcc(std::vector<Apple>& fieldOfApples, Player& player, Resources& resources, GameStates& settings, UI& UI) {
		for (auto& apple : fieldOfApples) {
			if (IsCircusCollide(player.position_, player.getSize(), apple.position_, apple.getSize())) {
				settings.appleIncrease();
				UI.appleCountUpdate(settings);

				apple.getRandomPosition();
				player.speedUp();
				AppleEatenSound(resources);
			}
		}
	}

	// Limited apples and player with acceleration
	void LimApplesWithNoAcc(std::vector<Apple>& fieldOfApples, Player& player, Resources& resources, GameStates& settings, UI& UI) {
		for (auto& apple : fieldOfApples) {
			if (!apple.isAppleEaten()) {
				if (IsCircusCollide(player.position_, player.getSize(), apple.position_, apple.getSize())) {
					settings.appleIncrease();
					UI.appleCountUpdate(settings);

					apple.appleEaten();
					AppleEatenSound(resources);
				}
			}
		}

		if (settings.eatenApples_ == settings.numOfApples) {
			pushGameState(settings, GameStateType::GameOver);
			GameOverSound(resources);
		}
	}

	// Limited apples and player without acceleration
	void LimApplesWithAcc(std::vector<Apple>& fieldOfApples, Player& player, Resources& resources, GameStates& settings, UI& UI) {
		for (auto& apple : fieldOfApples) {
			if (!apple.isAppleEaten()) {
				if (IsCircusCollide(player.position_, player.getSize(), apple.position_, apple.getSize())) {
					settings.appleIncrease();
					UI.appleCountUpdate(settings);

					apple.appleEaten();
					player.speedUp();
					AppleEatenSound(resources);
				}
			}
		}

		if (settings.eatenApples_ == settings.numOfApples) {
			pushGameState(settings, GameStateType::GameOver);
			GameOverSound(resources);
		}
	}

	// Draw apple
	void DrawApples(std::vector<Apple>& fieldOfApples, sf::RenderWindow& window) {
		for (auto& apple : fieldOfApples) {
			if (!apple.isAppleEaten()) {
				window.draw(apple.getSprite());
			}
		}
	}
}