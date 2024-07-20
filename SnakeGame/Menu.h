#pragma once

#include <unordered_map>
#include <algorithm>

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

	// Leader board menu
	class LeaderBoard {
	public:
		LeaderBoard(Resources& resources) : resources_(resources) {}

		void init(std::string menuName, float buttonSize, int drawablePositions, GameState& gameState);
		void sortTable(GameState& gameState);
		void addPlayer(GameState& gameState);
		void saveTable(GameState& gameState);

		int getPositionsCount() const;
		int getShortPosCount() const;
		
		sf::Text getName(int num) const;
		sf::Text getScore(int num) const;
		sf::Text getGeneralName() const;

		sf::Sprite getBackground() const;
		sf::Keyboard::Key getEscapeKey() const;

	private:
		int drawablePositions_ = 0;
		int shortDrawablePos_ = 0;

		float posX_ = 0;
		float posY_ = 0;
		float buttonSize_ = 0;

		sf::Text playerName_;
		sf::Text playerScore_;
		sf::Text menuName_;

		std::vector<std::pair<std::string, int>> tableText_;
		std::vector<std::pair<sf::Text, sf::Text>> liderBoard_;

		sf::Color mainButtonColor_ = sf::Color::White;
		sf::Sprite backgroundSprite_;

		sf::Keyboard::Key escapeKey_ = sf::Keyboard::B;

		Resources& resources_;
	};

	// Game ended pop up
	class PopUp : public Menu {
	public:
		PopUp(Resources& resources);

		void init(std::string popUpName, std::vector<std::string>& allButtons,
			float buttonSize = 40.f, sf::Color colorOfButtons = sf::Color::White);
		void reset();

		void enterName(sf::String letter);
		void deleteName();
		void savePlayerInTable(GameState& gameState);

		sf::Text getPlayerName();
		int getPositionsCount() const;

	private:
		int drawablePositions_ = 4;
		
		float buttonSize_ = 0;
		float posX_ = 0;
		float posY_ = 0;

		std::string DefaultPlayerName_ = "XYZ";
		sf::String playerInput_;
		sf::Text playerName_;		
	};

	// Movement in menu 
	void MainMenuMovement(Menu& mainMenu, GameState& gameState, const sf::Event& event);
	void DiffLvlMenuMovement(Menu& diffLvlChooseMenu, GameState& gameState, const sf::Event& event);
	void OptionsMenuMovement(Menu& optionsMenu, GameState& gameState, const sf::Event& event);
	void ExitMenuMovement(Menu& exitMenu, GameState& gameState, const sf::Event& event, sf::RenderWindow& window);
	void PauseMenuMovement(Menu& pauseMenu, GameState& gameState, const sf::Event& event);
	void GameOverMenuMovement(Menu& gameOverMenu, GameState& gameState, const sf::Event& event);

	// Leader board movement
	void LeaderBoardMovement(LeaderBoard& leaderBoard, GameState& gameState, const sf::Event& event);
	
	// Pop up movement
	void GameOverPopUpMovement(PopUp& popUp, GameState& gameState, const sf::Event& event);
	void ChooseNamePopUpMovement(PopUp& popUp, GameState& gameState, LeaderBoard& leaderBoard, const sf::Event& event);

	// Toolbox functions
	void ExitInPauseMenu(GameState& gameState);

	// Draw menu
	void DrawMenu(Menu& mainMenu, sf::RenderWindow& window);
	void DrawLeaderBoard(LeaderBoard& leaderBoard, sf::RenderWindow& window);
	void DrawGameOverLeaderBoard(LeaderBoard& leaderBoard, sf::RenderWindow& window);
	void DrawPopUp(PopUp& popUp, sf::RenderWindow& window, GameState& gameState);
}
