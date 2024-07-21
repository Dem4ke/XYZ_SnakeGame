#pragma once

#include "GameStates.h"
#include "Resources.h"

namespace SnakeGame {

	// Standart menus
	class Menu {
	public:
		Menu(Resources& resources) : resources_(resources) {}

		void init(std::string menuName, std::vector<std::string>& allButtons, 
				float buttonSize = 40.f, sf::Color colorOfButtons = sf::Color::White, int menuId = 0);
		void reset();
		void moveUp();
		void moveDown();

		size_t getButtonsCount() const;
		int getSelectedButton() const;
		sf::Text getButton(int num) const;
		sf::Text getGeneralName() const;
		sf::Sprite getBackground() const;

		sf::Keyboard::Key getUpKey() const;
		sf::Keyboard::Key getDownKey() const;
		sf::Keyboard::Key getLeftKey() const;
		sf::Keyboard::Key getRightKey() const;
		sf::Keyboard::Key getEscapeKey() const;
		sf::Keyboard::Key getEnterKey() const;

		void changeButton(int num, std::string newButton);

		void chooseButtonSound() const;
		void continueBackMusic() const;
		void stopBackMusic() const;
		void soundsOn() const;
		void soundsOff() const;

	protected:
		int selectedButton_ = 0;

		std::vector<sf::Text> buttons_;
		sf::Text menuName_;
		sf::Color mainButtonColor_ = sf::Color::White;
		sf::Color chosenButtonColor_ = sf::Color::Green;
		sf::Sprite backgroundSprite_;

		sf::Keyboard::Key upKey_ = sf::Keyboard::W;
		sf::Keyboard::Key downKey_ = sf::Keyboard::S;
		sf::Keyboard::Key leftKey_ = sf::Keyboard::A;
		sf::Keyboard::Key rightKey_ = sf::Keyboard::D;
		sf::Keyboard::Key escapeKey_ = sf::Keyboard::B;
		sf::Keyboard::Key enterKey_ = sf::Keyboard::Enter;

		Resources& resources_;
	};

	// Movement in menu 
	void MainMenuMovement(Menu& mainMenu, GameState& gameState, const sf::Event& event);
	void DiffLvlMenuMovement(Menu& diffLvlChooseMenu, GameState& gameState, const sf::Event& event);
	void OptionsMenuMovement(Menu& optionsMenu, GameState& gameState, const sf::Event& event);
	void ExitMenuMovement(Menu& exitMenu, GameState& gameState, const sf::Event& event, sf::RenderWindow& window);
	void PauseMenuMovement(Menu& pauseMenu, GameState& gameState, const sf::Event& event);
	void GameOverMenuMovement(Menu& gameOverMenu, GameState& gameState, const sf::Event& event);

	// Toolbox functions
	void ExitInPauseMenu(GameState& gameState);

	// Draw menu
	void DrawMenu(Menu& mainMenu, sf::RenderWindow& window);
}
