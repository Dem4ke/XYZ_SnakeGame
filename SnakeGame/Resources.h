#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

namespace SnakeGame {
	class Resources {
	public:
		Resources(float width, float height);

		void setTextures();
		void setSounds();
		void setFont();

		float getWindowWidth() const;
		float getWindowHeight() const;
		std::string getResourcesPath() const;

		sf::Texture snakeHeadTexture;
		sf::Texture snakeBodyTexture;
		sf::Texture appleTexture;
		sf::Texture wallTexture;

		sf::Texture mainMenuBackground;
		sf::Texture gameBackground;

		sf::SoundBuffer menuMove;
		sf::SoundBuffer appleEatenSound;
		sf::SoundBuffer gameOverSound;

		sf::Sound sound;
		sf::Font font;

	private:
		float width_ = 0;
		float height_ = 0;
		const std::string resourcesPath_ = "Resources/";
	};

	void SetSpriteSize(sf::Sprite& sprite, float desiredWidht, float desiredHeight);
	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);
	void MenuMovementSound(Resources& resources);
	void AppleEatenSound(Resources& resources);
	void GameOverSound(Resources& resources);
}
