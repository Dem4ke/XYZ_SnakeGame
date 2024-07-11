#include "Game.h"

int main() {
	int seed = static_cast <int> (time(nullptr));
	srand(seed);

	// Game initialization
	SnakeGame::Resources resources{ 800.f, 600.f };
	sf::RenderWindow window(sf::VideoMode(resources.getWindowWidth(), resources.getWindowHeight()), "Snake Game!");

	SnakeGame::Game game{ resources, window };

	game.initGame();

	// Main loop
	while (window.isOpen()) {

		// OS state checkout
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}

			// Update game state
			game.updateMenu(event);
		}

		// Update main gameplay 
		game.updateGame();
		game.gameOver();

		// Draw game
		window.clear();
		game.drawGame();
		window.display();
	}

	return 0;
}