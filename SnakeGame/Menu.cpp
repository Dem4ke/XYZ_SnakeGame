#include "Menu.h"

namespace SnakeGame {

	// Initialization of all menu buttons
	void Menu::init(std::string menuName, std::vector<std::string>& allButtons, float buttonSize) {
		float posX = resources_.getWindowWidth() / 2.f;
		float posY = resources_.getWindowHeight() / 3.f;

		// Initialization of background of menu
		background_.setSize(sf::Vector2f(resources_.getWindowWidth(), resources_.getWindowHeight()));
		background_.setFillColor(sf::Color::Black);
		background_.setPosition(0.f, 0.f);

		// Initialization of name of a game
		menuName_.setFont(resources_.font);
		menuName_.setCharacterSize(buttonSize * 1.5f);
		menuName_.setFillColor(sf::Color::Red);
		menuName_.setString(menuName);
		menuName_.setOrigin(sf::Vector2f(menuName_.getGlobalBounds().width / 2.f, menuName_.getGlobalBounds().height / 2.f));
		menuName_.setPosition(posX, posY - buttonSize);

		// Initialization of menu's buttons
		sf::Text menuButtons_;
		float space = buttonSize;
		menuButtons_.setFont(resources_.font);
		menuButtons_.setCharacterSize(buttonSize);
		menuButtons_.setFillColor(sf::Color::White);

		buttons_.clear();
		for (auto& i : allButtons) {
			menuButtons_.setString(i);
			menuButtons_.setOrigin(sf::Vector2f(menuButtons_.getGlobalBounds().width / 2.f, menuButtons_.getGlobalBounds().height / 2.f));
			menuButtons_.setPosition(posX, posY + space * 1.2f);
			buttons_.push_back(menuButtons_);
			space += buttonSize;
		}

		// Color of the first button
		int selectedButton_ = 0;
		buttons_[selectedButton_].setFillColor(sf::Color::Red);
	}

	void Menu::moveUp() {
		if (selectedButton_ >= 0) {
			buttons_[selectedButton_].setFillColor(sf::Color::White);
			--selectedButton_;

			if (selectedButton_ < 0) {
				selectedButton_ = buttons_.size() - 1;
			}
			buttons_[selectedButton_].setFillColor(sf::Color::Red);
		}
	}

	void Menu::moveDown() {
		size_t end = buttons_.size();

		if (selectedButton_ <= end) {
			buttons_[selectedButton_].setFillColor(sf::Color::White);
			++selectedButton_;

			if (selectedButton_ == end) {
				selectedButton_ = 0;
			}
			buttons_[selectedButton_].setFillColor(sf::Color::Red);
		}
	}

	size_t Menu::getButtonsCount() const { return buttons_.size(); }

	int Menu::getSelectedButton() const { return selectedButton_; }

	sf::Text Menu::getButton(int num) const { return buttons_[num]; }

	sf::Text Menu::getGeneralName() const { return menuName_; }

	sf::RectangleShape Menu::getBackground() const { return background_; }

	void Menu::changeButton(int num, std::string change) { buttons_[num].setString(change); }

	// LEADER BOAED INITIALIZATION

	//void LeaderBoard::init(std::string menuName, float buttonSize, GameStates& settings) {
	//	posX_ = resources_.getWindowWidth() / 2.f;
	//	posY_ = resources_.getWindowHeight() / 3.f;
	//	buttonSize_ = buttonSize;

	//	// Initialization of name of a game
	//	menuName_.setFont(resources_.font);
	//	menuName_.setCharacterSize(buttonSize_ * 1.5f);
	//	menuName_.setFillColor(sf::Color::Red);
	//	menuName_.setString(menuName);
	//	menuName_.setOrigin(sf::Vector2f(menuName_.getGlobalBounds().width / 2.f, menuName_.getGlobalBounds().height / 2.f));
	//	menuName_.setPosition(posX_, posY_ - buttonSize_);

	//	// Initialization of players names
	//	playerName_.setFont(resources_.font);
	//	playerName_.setCharacterSize(buttonSize_);
	//	playerName_.setFillColor(sf::Color::White);

	//	// Initialization of players score
	//	playerScore_.setFont(resources_.font);
	//	playerScore_.setCharacterSize(buttonSize_);
	//	playerScore_.setFillColor(sf::Color::White);

	//	table_["Hydra"] = settings.numOfApples;
	//	table_["Dominatus"] = settings.numOfApples - (settings.numOfApples / 4);
	//	table_["Alpha"] = settings.numOfApples / 2;
	//	table_["Omega"] = 1;
	//	table_["Player"] = 0;

	//	sortTable(settings);
	//}

	/*void LeaderBoard::sortTable(GameStates& settings) {
		float space = buttonSize_;

		table_["Player"] = settings.eatenApples_;

		auto cmp = [](std::pair<std::string, int> const& a, std::pair<std::string, int> const& b) {
			return a.second > b.second;
			};

		tableText_.clear();
		for (const auto& player : table_) {
			tableText_.push_back(player);
		}

		std::sort(begin(tableText_), end(tableText_), cmp);

		liderBoard_.clear();
		for (const auto& player : tableText_) {
			playerName_.setString(player.first);
			playerScore_.setString(std::to_string(player.second));

			playerName_.setOrigin(sf::Vector2f(playerName_.getGlobalBounds().width / 2.f, playerName_.getGlobalBounds().height / 2.f));
			playerScore_.setOrigin(sf::Vector2f(playerScore_.getGlobalBounds().width / 2.f, playerScore_.getGlobalBounds().height / 2.f));

			playerName_.setPosition(posX_, posY_ + space * 1.2f);
			playerScore_.setPosition(posX_ + buttonSize_ * 4.f, posY_ + space * 1.2f);

			liderBoard_.push_back({ playerName_ , playerScore_ });

			space += buttonSize_;
		}
	}*/

	size_t LeaderBoard::getPositionsCount() const { return liderBoard_.size(); }

	sf::Text LeaderBoard::getName(int num) const { return liderBoard_[num].first; }

	sf::Text LeaderBoard::getScore(int num) const { return liderBoard_[num].second; }

	sf::Text LeaderBoard::getGeneralName() const { return menuName_; }

	// FUNCTIONS

	void MainMenuMovement(Menu& mainMenu, GameStates& settings, const sf::Event& event) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				mainMenu.moveUp();
			}
			else if (event.key.code == sf::Keyboard::Down) {
				mainMenu.moveDown();
			}
			else if (event.key.code == sf::Keyboard::Escape) {
				pushGameState(settings, GameStateType::ExitDialog);
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				if (mainMenu.getSelectedButton() == 0) {
					pushGameState(settings, GameStateType::Game);
				}
				else if (mainMenu.getSelectedButton() == 1) {
					pushGameState(settings, GameStateType::LeaderBoard);
				}
				else if (mainMenu.getSelectedButton() == 2) {
					pushGameState(settings, GameStateType::Options);
				}
				else if (mainMenu.getSelectedButton() == 3) {
					pushGameState(settings, GameStateType::ExitDialog);
				}
			}
		}
	}

	void OptionsMenuMovement(Menu& optionsMenu, GameStates& settings, const sf::Event& event) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				optionsMenu.moveUp();
			}
			else if (event.key.code == sf::Keyboard::Down) {
				optionsMenu.moveDown();
			}
			else if (event.key.code == sf::Keyboard::Escape) {
				popGameState(settings);
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				if (optionsMenu.getSelectedButton() == 0) {
					if (optionsMenu.getButton(0).getString() == "Acceleration: On") {
						optionsMenu.changeButton(0, "Acceleration: Off");
						settings.gameSettings &= ~(GameOptions::isPlayerAccelerated);
					}
					else if (optionsMenu.getButton(0).getString() == "Acceleration: Off") {
						optionsMenu.changeButton(0, "Acceleration: On");
						settings.gameSettings |= GameOptions::isPlayerAccelerated;
					}
				}
				else if (optionsMenu.getSelectedButton() == 1) {
					if (optionsMenu.getButton(1).getString() == "Infinite apples: On") {
						optionsMenu.changeButton(1, "Infinite apples: Off");
						settings.gameSettings &= ~(GameOptions::isApplesInfinite);
					}
					else if (optionsMenu.getButton(1).getString() == "Infinite apples: Off") {
						optionsMenu.changeButton(1, "Infinite apples: On");
						settings.gameSettings |= GameOptions::isApplesInfinite;
					}
				}
			}
		}
	}

	void ExitMenuMovement(Menu& exitMenu, GameStates& settings, const sf::Event& event, sf::RenderWindow& window) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				exitMenu.moveUp();
			}
			else if (event.key.code == sf::Keyboard::Down) {
				exitMenu.moveDown();
			}
			else if (event.key.code == sf::Keyboard::Escape) {
				popGameState(settings);
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				if (exitMenu.getSelectedButton() == 0) {
					window.close();
					return;
				}
				else if (exitMenu.getSelectedButton() == 1) {
					popGameState(settings);
				}
			}
		}
	}

	void LeaderBoardMovement(LeaderBoard& leaderBoard, GameStates& settings, const sf::Event& event) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {
				popGameState(settings);
			}
		}
	}

	void PauseMenuMovement(Menu& pauseMenu, GameStates& settings, const sf::Event& event) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				pauseMenu.moveUp();
			}
			else if (event.key.code == sf::Keyboard::Down) {
				pauseMenu.moveDown();
			}
			else if (event.key.code == sf::Keyboard::Escape) {
				popGameState(settings);
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				if (pauseMenu.getSelectedButton() == 0) {
					pushGameState(settings, GameStateType::GameReset);
				}
				else if (pauseMenu.getSelectedButton() == 1) {
					popGameState(settings);
				}
			}
		}
	}

	void GameOverMenuMovement(Menu& gameOverMenu, GameStates& settings, const sf::Event& event) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Enter) {
				pushGameState(settings, GameStateType::GameReset);
			}
			else if (event.key.code == sf::Keyboard::Escape) {
				pushGameState(settings, GameStateType::GameReset);
			}
		}
	}

	void ExitInPauseMenu(GameStates& settings) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			pushGameState(settings, GameStateType::Pause);
		}
	}

	void DrawMenu(Menu& menu, sf::RenderWindow& window) {
		window.draw(menu.getBackground());
		window.draw(menu.getGeneralName());
		for (int i = 0, it = menu.getButtonsCount(); i < it; ++i) {
			window.draw(menu.getButton(i));
		}
	}

	void DrawLeaderBoard(LeaderBoard& leaderBoard, sf::RenderWindow& window) {
		window.draw(leaderBoard.getGeneralName());
		for (int i = 0, it = leaderBoard.getPositionsCount(); i < it; ++i) {
			window.draw(leaderBoard.getName(i));
			window.draw(leaderBoard.getScore(i));
		}
	}
}