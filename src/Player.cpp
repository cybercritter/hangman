
#include "Player.h"
#include <stdexcept>

Player::Player(const std::string& name, int score, int level) {
	// TODO - implement Player::Player

}

void Player::displayStatus() {
	// TODO - implement Player::displayStatus
	throw std::runtime_error("Not yet implemented");
}

bool Player::guessLetter(char letter) {
	// TODO - implement Player::guessLetter
	throw std::runtime_error("Not yet implemented");
}

uint32_t Player::getAttemptsLeft() {
	// TODO - implement Player::getAttemptsLeft
	throw std::runtime_error("Not yet implemented");
}

std::set<char> Player::getGuessedLetters() {
	return this->guessedLetters;
}

std::string Player::getName() {
	return this->name;
}

/**
 * Sets the player's score.
 * @param newScore The new score to be set for the player.
 */
void Player::setScore(int newScore)
{
	score = newScore;
}

void Player::setLevel(int newLevel)
{
	level = newLevel;
}

