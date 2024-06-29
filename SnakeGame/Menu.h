#pragma once

#include <unordered_map>
#include <algorithm>
#include "Settings.h"
#include "Resources.h"

namespace SnakeGame {

	class Menu {
	public:
		Menu(Resources& resources) : resources_(resources) {}

		void init(std::string menuName, std::vector<std::string>& allButtons, 
				float buttonSize, sf::Color colorOfButtons, int menuId);
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

	private:
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

	class LeaderBoard {
	public:
		LeaderBoard(Resources& resources) : resources_(resources) {}

		void init(std::string menuName, float buttonSize, GameStates& settings);
		void sortTable(GameStates& settings);

		size_t getPositionsCount() const;
		sf::Text getName(int num) const;
		sf::Text getScore(int num) const;
		sf::Text getGeneralName() const;

	private:
		float posX_ = 0;
		float posY_ = 0;
		float buttonSize_ = 0;

		sf::Text playerName_;
		sf::Text playerScore_;
		sf::Text menuName_;

		std::vector<std::pair<std::string, int>> tableText_;
		std::vector<std::pair<sf::Text, sf::Text>> liderBoard_;
		std::unordered_map<std::string, int> table_;

		Resources& resources_;
	};

	// Movement in menu 
	void MainMenuMovement(Menu& mainMenu, GameStates& settings, const sf::Event& event);
	void DiffLvlMenuMovement(Menu& diffLvlChooseMenu, GameStates& gameStates, const sf::Event& event);
	void OptionsMenuMovement(Menu& optionsMenu, GameStates& settings, const sf::Event& event);
	void ExitMenuMovement(Menu& exitMenu, GameStates& settings, const sf::Event& event, sf::RenderWindow& window);
	void PauseMenuMovement(Menu& pauseMenu, GameStates& settings, const sf::Event& event);
	void GameOverMenuMovement(Menu& gameOverMenu, GameStates& settings, const sf::Event& event);
	void LeaderBoardMovement(LeaderBoard& leaderBoard, GameStates& settings, const sf::Event& event);
	void ExitInPauseMenu(GameStates& settings);

	// Draw menu
	void DrawMenu(Menu& mainMenu, sf::RenderWindow& window);
	void DrawLeaderBoard(LeaderBoard& leaderBoard, sf::RenderWindow& window);
}
