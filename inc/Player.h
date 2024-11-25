#ifndef PLAYER_H
#define PLAYER_H
#include <FileManager.h>

/**
 * @class Player
 * @brief Represents a player in the game.
 *
 * This class encapsulates the properties and behaviors of a player, providing
 * methods to get and set the player's name and level, as well as display the
 * player's status.
 */
class Player
{
public:
	/**
	 * Constructs a Player object with the given name.
	 *
	 * @param name The name of the player.
	 */
	explicit Player(std::string name);

	/**
	 * @brief Default destructor for the Player class.
	 *
	 * This destructor is explicitly defined as the default destructor.
	 * It is used to clean up resources when an instance of the Player class
	 * is destroyed. The =default keyword tells the compiler to automatically
	 * generate the destructor.
	 */
	~Player() = default;

	/**
	 * Gets the name of the Player.
	 *
	 * @return The name of the Player as a std::string.
	 */
	[[nodiscard]] std::string getName();

	/**
	 * @brief Retrieves the current level of the player.
	 *
	 * @return The player's current level as an integer.
	 */
	[[nodiscard]] int getLevel() const;

	/**
	 * @brief Sets the player's level.
	 *
	 * This function assigns a new value to the player's level.
	 *
	 * @param level The new level to be assigned to the player.
	 */
	void setLevel(int level);

private:
	/**
	 * @brief Represents the name of a player.
	 */
	std::string name;

	/**
	 * @brief Represents the player's level.
	 *
	 * This integer variable stores the current level of the player.
	 * It is used in functions such as displayPlayerStatus, setLevel, and getLevel.
	 */
	int level{0};
};
#endif
