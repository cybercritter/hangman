#ifndef COMPUTER_H
#define COMPUTER_H
#include <map>
#include <Player.h>
#include <string>
#include <WordManager.h>

/**
 * A map to store words and their corresponding scores.
 */
class Computer
{
public:
	Computer() = delete;
	~Computer() = delete;

	/**
	 * Retrieves the word list of the computer.
	 *
	 * This function accesses and returns the word list maintained by the Computer class,
	 * where each word is associated with an integer value representing its frequency or score.
	 *
	 * @throw Throws an exception if the function is not yet implemented.
	 */
	void getWordList();

	/**
	 * @brief Calculates the score based on the current state of the word list.
	 *
	 * This method analyzes the words contained in the wordList map and calculates
	 * a score for the computer. The precise scoring algorithm and rules are to
	 * be defined and implemented.
	 *
	 * @throw std::runtime_error Thrown if the method is not yet implemented.
	 */
	void calculateScore();

	/**
	 * @brief Draws the computer's state on the screen.
	 *
	 * This method is used to render or visually update the computer-related
	 * elements in the application's user interface. The specific implementation
	 * of this method needs to be completed.
	 *
	 * @throws Throws an exception indicating the method is not yet implemented.
	 */
	void draw();

private:
	/**
	 * @brief A map that associates words with their corresponding integer values.
	 *
	 * This variable stores a collection of words as keys and their associated integer values.
	 * It can be used for tasks like word frequency counting, scoring, or any other operation
	 * that requires associating words with numerical data.
	 */
	std::map<std::string, int> wordList;

	/**
	 * An instance of the Player class.
	 *
	 * This variable represents a player in the game and provides various functionalities
	 * and attributes associated with the player. The specific methods and properties
	 * available through this instance depend on the implementation of the Player class.
	 */
	Player player;
	/**
	 * An instance of the FileManager class responsible for handling file operations.
	 *
	 * This variable is used to manage file-related tasks such as reading word data and
	 * writing high scores.
	 */
	WordManager wordManager;
};

#endif
