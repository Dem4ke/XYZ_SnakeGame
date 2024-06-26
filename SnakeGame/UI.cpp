#include "UI.h"

namespace SnakeGame {
	void UI::init(float buttonSize) {
		float posX = resources_.getWindowWidth() / 2.f;
		float posY = resources_.getWindowHeight() / 3.f;

		// Initialization of conrtol help
		controlHelp_.setFont(resources_.font);
		controlHelp_.setCharacterSize(buttonSize);
		controlHelp_.setFillColor(sf::Color::White);
		controlHelp_.setString("Use arrays to move, ESC to pause");
		controlHelp_.setPosition(resources_.getWindowWidth() - controlHelp_.getGlobalBounds().width * 1.1f,
			controlHelp_.getGlobalBounds().height);

		// Initialization of player score
		score_.setFont(resources_.font);
		score_.setCharacterSize(buttonSize);
		score_.setFillColor(sf::Color::White);
		score_.setString("Apples eaten " + std::to_string(0));
		score_.setPosition(score_.getGlobalBounds().width / 2.f, score_.getGlobalBounds().height);
	}

	void UI::appleCountUpdate(GameStates& settings) {
		score_.setString("Apples eaten " + std::to_string(settings.eatenApples_));
	}

	sf::Text UI::getHelp() const { return controlHelp_; }
	sf::Text UI::getScore() const { return score_; }

	void DrawUI(UI& UI, sf::RenderWindow& window) {
		window.draw(UI.getHelp());
		window.draw(UI.getScore());
	}
}