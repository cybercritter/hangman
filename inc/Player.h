#ifndef PLAYER_H
#define PLAYER_H
#include <IPlayer.h>

/**
 * An implementation of the IPlayer interface representing a player in a game. This class encapsulates the properties and behaviors of a player, such as their name, score, level, guessed letters, and the number of attempts left.
 */
class Player final : IPlayer {

private:
	/**
	 * A set containing the remaining attempts a player has. Each entry in the set represents the number of attempts left for the player. The set may be modified throughout the gameplay, decreasing in size as the player makes incorrect guesses. 
	 */
	std::set<int> attemptsLeft;
	/**
	 * A set of characters representing the guessed letters by a player. This variable stores the letters that have been guessed correctly or incorrectly by the player during the game. Each character in this set represents a letter that the player has attempted to guess. The use of a set ensures that each letter is unique and there are no duplicate entries. 
	 */
	std::set<char> guessedLetters;
	/**
	 * The name of the player. 
	 */
	std::string name;
	/**
	 * Holds the player's current score. The score variable keeps track of the player's accumulated points throughout the game. It starts at 0 and increases as the player progresses. 
	 */
	uint32_t score{};
	/**
	 * Represents the current level of the player. This variable tracks the player's progression through different levels. It is initialized to 0 and can be incremented as the player advances to higher levels in the game. 
	 */
	uint16_t level{};
	/**
	 * A set containing letters that the player has guessed incorrectly. This set is used to track and display the letters that have been tried but are not present in the target word. 
	 */
	std::set<char> incorrectGuessedLetters;

public:
	/**
	 * Constructs a Player object with the specified name, score, and level.
	 * nameThe name of the player. scoreThe score of the player. levelThe level of the player. A Player object. A Player object. 
	 */
	Player(const std::string& name, uint32_t score, uint16_t level);

	/**
	 * Destructor for the Player class.
	 * Cleans up resources and performs necessary finalization tasks before the Player object is destroyed. Overrides the virtual destructor from the IPlayer interface. 
	 */
	~Player() override = default;

	/**
	 * Displays the current status of the player. This method shows the player's current score, level, and other relevant game information. It is meant to provide feedback to the player about their ongoing progress in the game.
	 * std::runtime_error if the status cannot be displayed.
	 */
	void displayStatus() override;

	/**
	 * Attempts to guess a letter in the current game.
	 * letterThe letter the player is guessing. True if the guessed letter is in the word, false otherwise. True if the guessed letter is in the word, false otherwise. 
	 */
	bool guessLetter(/* The letter the player is guessing.  */char letter) override;

	/**
	 * Retrieves the number of attempts left for the player.
	 * The number of remaining attempts as uint32_t. The number of remaining attempts as uint32_t.
	 */
	uint32_t getAttemptsLeft() override;

	/**
	 * Retrieves the set of guessed letters for the player.
	 * A set containing the letters that the player has already guessed. A set containing the letters that the player has already guessed. 
	 */
	std::set<char> getGuessedLetters() override;

	/**
	 * Retrieves the name of the player.
	 * The name of the player as a string. The name of the player as a string. 
	 */
	std::string getName() override;
};

#endif
