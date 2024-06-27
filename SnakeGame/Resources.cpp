#include <cassert>
#include "Resources.h"

namespace SnakeGame {
	Resources::Resources(float width, float height) : width_(width), height_(height) {
		setTextures();
		setSounds();
		setFont();
	}

	// Load texures from resources path
	void Resources::setTextures() {
		assert(snakeHeadTexture.loadFromFile(resourcesPath_ + "Snake_head.png"));
		assert(snakeBodyTexture.loadFromFile(resourcesPath_ + "Snake_Body.png"));
		assert(appleTexture.loadFromFile(resourcesPath_ + "Apple.png"));
		assert(wallTexture.loadFromFile(resourcesPath_ + "wall.png"));
		assert(mainMenuBackground.loadFromFile(resourcesPath_ + "Background.jpg"));
		assert(gameBackground.loadFromFile(resourcesPath_ + "Background.jpg"));
	}

	// Load sounds from resources path
	void Resources::setSounds() {
		assert(menuMove.loadFromFile(resourcesPath_ + "Theevilsocks__menu-hover.wav"));
		assert(appleEatenSound.loadFromFile(resourcesPath_ + "AppleEat.wav"));
		assert(gameOverSound.loadFromFile(resourcesPath_ + "Maodin204__Lose.wav"));
	}

	// Load fonts from resources path
	void Resources::setFont() {
		assert(font.loadFromFile(resourcesPath_ + "Fonts/Roboto-Regular.ttf"));
	}

	float Resources::getWindowWidth() const { return width_; }

	float Resources::getWindowHeight() const { return height_; }

	std::string Resources::getResourcesPath() const { return resourcesPath_; }

	void SetSpriteSize(sf::Sprite& sprite, float desiredWidht, float desiredHeight) {
		sf::FloatRect spriteRect = sprite.getLocalBounds(); // get sprite size from corner
		sf::Vector2f scale = { desiredWidht / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY) {
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(sf::Vector2f(originX * spriteRect.width, originY * spriteRect.height));
	}

	// Init sound of menu move
	void MenuMovementSound(Resources& resources) {
		resources.sound.setBuffer(resources.menuMove);
		resources.sound.setVolume(5.f);
		resources.sound.play();
	}

	// Init sound of eat an apples
	void AppleEatenSound(Resources& resources) {
		resources.sound.setBuffer(resources.appleEatenSound);
		resources.sound.setVolume(5.f);
		resources.sound.play();
	}

	// Init game over sound
	void GameOverSound(Resources& resources) {
		resources.sound.setBuffer(resources.gameOverSound);
		resources.sound.setVolume(5.f);
		resources.sound.play();
	}
}