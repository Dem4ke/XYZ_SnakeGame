#include "Player.h"

namespace SnakeGame {

	// PLAYER INITIALIZATION

	//void Player::init(float playerSize, float playerSpeed) {
	//	// Initialization of player's characteristics
	//	direction_ = PlayerDirection::Right;
	//	position_ = { resources_.getWindowWidth() / 2.f, resources_.getWindowHeight() / 2.f };
	//	size_ = playerSize;
	//	speed_ = playerSpeed;
	//	sprite_.setRotation(0.f);

	//	// Init player sprite
	//	sprite_.setTexture(resources_.playerTexture);
	//	SetSpriteSize(sprite_, size_, size_);
	//	SetSpriteRelativeOrigin(sprite_, 0.5f, 0.5f);

	//}

	//void Player::moveRight() {
	//	direction_ = PlayerDirection::Right;
	//}

	//void Player::moveLeft() {
	//	direction_ = PlayerDirection::Left;
	//}

	//void Player::moveUp() {
	//	direction_ = PlayerDirection::Up;
	//}

	//void Player::moveDown() {
	//	direction_ = PlayerDirection::Down;
	//}

	//void Player::speedUp() {
	//	speed_ += acceleration_;
	//}

	//// Rotate sprite of player 
	//void Player::rotateSprite(float rotateDegree) {
	//	sprite_.setRotation(rotateDegree);
	//}

	//// Set sprite in normal view
	//void Player::setNormalPlayerSprite() {
	//	SetSpriteSize(sprite_, size_, size_);
	//}

	//// Set sprite in mirrored view
	//void Player::setMirrorPlayerSprite() {
	//	SetSpriteSize(sprite_, -size_, size_);
	//}

	//// Set position to sprite
	//void Player::setSpritePosition(float x, float y) {
	//	sprite_.setPosition(x, y);
	//}

	//float Player::getSize() const { return size_; }

	//float Player::getSpeed() const { return speed_; }

	//sf::RectangleShape Player::getBackground() const { return background_; }

	//sf::Sprite Player::getSprite() const { return sprite_; }

	//PlayerDirection Player::getDirection() const { return direction_; }

	//// FUNCTIONS

	//// Player movement
	//void PlayerMove(Player& player, const float& deltaTime) {
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
	//		player.moveRight();
	//	}
	//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
	//		player.moveUp();
	//	}
	//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
	//		player.moveLeft();
	//	}
	//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
	//		player.moveDown();
	//	}

	//	// Change player "speed" direction to move player
	//	switch (player.getDirection()) {
	//	case PlayerDirection::Right: {
	//		player.position_.x += player.getSpeed() * deltaTime;
	//		break;
	//	}
	//	case PlayerDirection::Up: {
	//		player.position_.y -= player.getSpeed() * deltaTime;
	//		break;
	//	}
	//	case PlayerDirection::Left: {
	//		player.position_.x -= player.getSpeed() * deltaTime;
	//		break;
	//	}
	//	case PlayerDirection::Down: {
	//		player.position_.y += player.getSpeed() * deltaTime;
	//		break;
	//	}
	//	}
	//}

	//// Window border collision
	//void OutOfWindow(Player& player, Resources& resources, GameStates& settings) {
	//	if (player.position_.x + player.getSize() / 2.f > resources.getWindowWidth() ||
	//		player.position_.x - player.getSize() / 2.f < 0.f ||
	//		player.position_.y + player.getSize() / 2.f > resources.getWindowHeight() ||
	//		player.position_.y - player.getSize() / 2.f < 0.f) {

	//		GameOverSound(resources);
	//		pushGameState(settings, GameStateType::GameOver);
	//	}
	//}

	//void DrawPlayer(Player& player, sf::RenderWindow& window) {
	//	
	//	player.setSpritePosition(player.position_.x, player.position_.y);
	//	window.draw(player.getSprite());

	//	// Orient player sprite according to player direction
	//	if (player.getDirection() == PlayerDirection::Left) {
	//		player.setMirrorPlayerSprite();
	//		player.rotateSprite(0.f);
	//	}
	//	else {
	//		player.setNormalPlayerSprite();
	//		player.rotateSprite(static_cast <int> (player.getDirection()) * -90);
	//	}
	//}
}