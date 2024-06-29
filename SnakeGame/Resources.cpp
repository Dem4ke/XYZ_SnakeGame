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
		// Little sounds
		assert(menuMove.loadFromFile(resourcesPath_ + "Owlstorm__Snake_hit.wav"));
		assert(appleEatenSound.loadFromFile(resourcesPath_ + "AppleEat.wav"));
		assert(gameOverSound.loadFromFile(resourcesPath_ + "Maodin204__Lose.wav"));
		assert(hitSound.loadFromFile(resourcesPath_ + "Owlstorm__Snake_hit.wav"));
		assert(soundOfChoose.loadFromFile(resourcesPath_ + "Theevilsocks__menu-hover.wav"));

		// Long sounds or background music (not loads file but opens it for a whole session)
		assert(backMusic.openFromFile(resourcesPath_ + "Clinthammer__Background_Music.wav"));
	}

	// Load fonts from resources path
	void Resources::setFont() {
		assert(font.loadFromFile(resourcesPath_ + "Fonts/Roboto-Regular.ttf"));
	}

	float Resources::getWindowWidth() const { return width_; }

	float Resources::getWindowHeight() const { return height_; }

	std::string Resources::getResourcesPath() const { return resourcesPath_; }

	// SPRITES

	void SetSpriteSize(sf::Sprite& sprite, float desiredWidht, float desiredHeight) {
		sf::FloatRect spriteRect = sprite.getLocalBounds(); // get sprite size from corner
		sf::Vector2f scale = { desiredWidht / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY) {
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(sf::Vector2f(originX * spriteRect.width, originY * spriteRect.height));
	}

	// SOUNDS AND MUSIC 
	
	// Change volume of sounds
	void SetSoundsVolume(Resources& resources, float volume) {
		resources.sound.setVolume(volume);
	}
	// Change volume of music
	void SetMusicVolume(Resources& resources, float volume) {
		resources.backMusic.setVolume(volume);
	}

	// Init sound of menu move
	void MenuMovementSound(Resources& resources) {
		resources.sound.setBuffer(resources.menuMove);
		resources.sound.play();
	}

	// Init sound of eat an apples and play
	void AppleEatenSound(Resources& resources) {
		resources.sound.setBuffer(resources.appleEatenSound);
		resources.sound.play();
	}

	// Init game over sound and play
	void GameOverSound(Resources& resources) {
		resources.sound.setBuffer(resources.gameOverSound);
		resources.sound.play();
	}

	// Init sound of a click on any button
	void SoundOfChoose(Resources& resources) {
		resources.sound.setBuffer(resources.soundOfChoose);
		resources.sound.play();
	}

	// Start playing background music 
	void PlayBackMusic(Resources& resources) {
		resources.backMusic.play();
		resources.backMusic.setLoop(true);
	}

	// Stop playing background music
	void StopBackMusic(Resources& resources) {
		resources.backMusic.pause();
	}
}