
#include <Player.h>

#include <iostream>


/**
 * Constructor to initialize a Player object with a given name.
 *
 * @param name the name of the player to initialize.
 * @return A new instance of the Player class.
 */
Player::Player(std::string name) :
	name(std::move(name))
{
}

/**
 * @brief Displays the current status of the player.
 *
 * This method prints the player's name and level to the standard output.
 */
void Player::displayPlayerStatus() const
{
	std::cout << "Player: " << name << std::endl << " Level: " << level << std::endl;
}


/**
 * Retrieves the name of the player.
 *
 * @return The name of the player as a string.
 */
std::string Player::getName()
{
	return this->name;
}

/**
 * @brief Sets the level of the player.
 *
 * This method updates the level of the current player instance.
 *
 * @param level The new level to be set for the player.
 */
void Player::setLevel(const int level)
{
	this->level = level;
}

/**
 * Retrieves the current level of the player.
 *
 * @return The level of the player as an integer.
 */
int Player::getLevel() const
{
	return this->level;
}



