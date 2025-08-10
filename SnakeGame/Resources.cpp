#include <cassert>
#include "Resources.h"

namespace SnakeGame {
	Resources::Resources(float width, float height) : width_(width), height_(height) {
		setTextures();
		setBackgrounds();
		setSounds();
		setFont();
	}

	// Load texures from resources path
	void Resources::setTextures() {
		bool isLoaded;

		isLoaded = snakeHeadTexture.loadFromFile(resourcesPath_ + texturesPath_ + "Snake_head.png");
		assert(bIsLoaded);

		isLoaded = snakeBodyTexture.loadFromFile(resourcesPath_ + texturesPath_ + "Snake_Body.png");
		assert(bIsLoaded);

		isLoaded = appleTexture.loadFromFile(resourcesPath_ + texturesPath_ + "Apple.png");
		assert(bIsLoaded);

		isLoaded = wallTexture.loadFromFile(resourcesPath_ + texturesPath_ + "wall.png");
		assert(bIsLoaded);
	}

	// Loads backgrounds from resources path
	void Resources::setBackgrounds() {
		bool isLoaded;

		isLoaded = mainMenuBackground.loadFromFile(resourcesPath_ + backgroundsPath_ + "Menu_background.jpg");
		assert(bIsLoaded);

		isLoaded = gameBackground.loadFromFile(resourcesPath_ + backgroundsPath_ + "Background.jpg");
		assert(bIsLoaded);
	}

	// Load sounds from resources path
	void Resources::setSounds() {
		// Little sounds
		bool isLoaded;

		isLoaded = menuMove.loadFromFile(resourcesPath_ + soundsPath_ + "Owlstorm__Snake_hit.wav");
		assert(bIsLoaded);

		isLoaded = appleEatenSound.loadFromFile(resourcesPath_ + soundsPath_ + "AppleEat.wav");
		assert(bIsLoaded);

		isLoaded = gameOverSound.loadFromFile(resourcesPath_ + soundsPath_ + "Maodin204__Lose.wav");
		assert(bIsLoaded);

		isLoaded = hitSound.loadFromFile(resourcesPath_ + soundsPath_ + "Owlstorm__Snake_hit.wav");
		assert(bIsLoaded);

		isLoaded = soundOfChoose.loadFromFile(resourcesPath_ + soundsPath_ + "Theevilsocks__menu-hover.wav");
		assert(bIsLoaded);

		// Long sounds or background music (not loads file but opens it for a whole session)
		isLoaded = backMusic.openFromFile(resourcesPath_ + soundsPath_ + "Clinthammer__Background_Music.wav");
		assert(bIsLoaded);
	}

	// Load fonts from resources path
	void Resources::setFont() {
		bool isLoaded;

		isLoaded = font.loadFromFile(resourcesPath_ + fontsPath_ + "Roboto-Regular.ttf");
		assert(bIsLoaded);
	}

	float Resources::getWindowWidth() const { return width_; }

	float Resources::getWindowHeight() const { return height_; }

	std::string Resources::getResourcesPath() const { return resourcesPath_; }

	// SPRITES

	void SetSpriteSize(sf::Sprite& sprite, float desiredWidht, float desiredHeight) {
		sf::FloatRect spriteRect = sprite.getLocalBounds(); // get sprite size from the corner
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
		resources.sound.setVolume(5.f);
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