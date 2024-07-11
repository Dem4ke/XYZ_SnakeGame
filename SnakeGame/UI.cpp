#include "UI.h"

namespace SnakeGame {
	void UI::init(float buttonSize) {
		// Initialization of conrtol help
		controlHelp_.setFont(resources_.font);
		controlHelp_.setCharacterSize(buttonSize);
		controlHelp_.setFillColor(sf::Color::White);
		controlHelp_.setString("Use WASD to move, P to pause");
		controlHelp_.setPosition(resources_.getWindowWidth() - controlHelp_.getGlobalBounds().width * 1.1f,
			controlHelp_.getGlobalBounds().height);

		// Initialization of player score
		score_.setFont(resources_.font);
		score_.setCharacterSize(buttonSize);
		score_.setFillColor(sf::Color::White);
		score_.setString("Your score " + std::to_string(0));
		score_.setPosition(score_.getGlobalBounds().width / 2.f, score_.getGlobalBounds().height);
	}

	void UI::scoreUpdate(GameState& gameStates) {
		score_.setString("Your score " + std::to_string(gameStates.getScore()));
	}

	sf::Text UI::getHelp() const { return controlHelp_; }

	sf::Text UI::getScore() const { return score_; }

	// FUNCTIONS

	void DrawUI(UI& UI, sf::RenderWindow& window) {
		window.draw(UI.getHelp());
		window.draw(UI.getScore());
	}
}