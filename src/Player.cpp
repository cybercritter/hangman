#include "Player.h"

Player::Player(/* The name of the player.  */std::string name, /* The score of the player.  */uint32_t score, /* The level of the player.  */uint16_t level) {
	// TODO - implement Player::Player
	throw "Not yet implemented";
}

void Player::displayStatus() {
	// TODO - implement Player::displayStatus
	throw "Not yet implemented";
}

bool Player::guessLetter(/* The letter the player is guessing.  */char letter) {
	// TODO - implement Player::guessLetter
	throw "Not yet implemented";
}

uint32_t Player::getAttemptsLeft() {
	// TODO - implement Player::getAttemptsLeft
	throw "Not yet implemented";
}

std::set<char> Player::getGuessedLetters() {
	return this->guessedLetters;
}

std::string Player::getName() {
	return this->name;
}
