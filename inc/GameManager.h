#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#define COMPUTER_H
#include <map>
#include <Player.h>
#include <string>
#include <types.h>
#include <FileManager.h>
#include <set>

/**
 * @class GameManager
 * @brief Manages the core game logic and state for the Hangman game.
 */
class GameManager
{

public:
	/**
	* @brief Default constructor for the GameManager class.
	*/
	GameManager() = default;

	/**
	 * @brief Deleted copy constructor to prevent copying of the GameManager instance.
	 *
	 * @param other The GameManager instance to copy from.
	 */
	GameManager(const GameManager& other) = delete;

	/**
	 * @brief Assignment operator is deleted to prevent copying of GameManager instances.
	 * @param other The other GameManager instance to be assigned.
	 * @return This method does not return anything as it is deleted.
	 */
	GameManager& operator=(const GameManager& other) = delete;

	/**
	 * Destructor for the GameManager class.
	 *
	 * This method is responsible for cleaning up resources used by the
	 * GameManager instance. Specifically, it deallocates the memory
	 * allocated for the `player` object and sets the `player` pointer
	 * to nullptr to ensure it does not point to a deallocated memory.
	 */
	~GameManager();

	/**
	 * @brief Selects a new random word from the current word list and updates the target word.
	 *
	 * Ensures that the word list is not empty before selecting and setting a random word from the list to
	 * the targetWord member variable.
	 *
	 * If the word list is found to be empty, it prints an error message and exits early.
	 */
	void getNewWord();
	/**
	 * @brief Draws the current state of the game.
	 *
	 * This method displays the current hangman figure, the target word with unguessed
	 * letters masked, the list of incorrect guessed letters, and the list of all guessed letters.
	 *
	 * It calls helper methods to display the hangman figure and the correctly guessed portions of the target word.
	 */
	void draw() const;
	/**
	 * @brief Displays the current state of the target word with guessed and un-guessed letters.
	 *
	 * This method prints the target word, revealing letters that have been correctly guessed
	 * and displaying underscores for letters that have not yet been guessed. Each character
	 * of the word is followed by a space for readability. The method ends the line after
	 * displaying the entire word.
	 */
	void displayWord() const;

	/**
	 * @brief Displays the current state of the hangman figure based on the number of incorrect guesses.
	 *
	 * This function draws the hangman figure on the console. The drawing changes based on the number
	 * of incorrect letters guessed. It also displays the number of attempts left.
	 */
	void displayHangman() const;

	/**
	 * @brief Starts a new game session of Hangman.
	 *
	 * This method initializes the game by requesting the player's name
	 * and setting up the Player instance. It also prints a welcome message
	 * and sets up the game environment for the player to begin playing Hangman.
	 */
	void start();

	/**
	 * Displays a menu prompting the player to guess a letter.
	 *
	 * This method is responsible for:
	 * 1. Prompting the player to enter a letter.
	 * 2. Capturing the entered letter.
	 * 3. Converting the letter to lowercase.
	 * 4. Invoking the guessLetter method to process the guessed letter.
	 */

	void menu();


	/**
	 * @brief Handles the result of a player's guess in the Hangman game.
	 *
	 * Updates the state based on whether the guessed letter is found in the word.
	 * This includes updating the list of guessed letters, decrementing attempts, and
	 * determining if the maximum number of tries has been exceeded.
	 *
	 * @param letter The letter that was guessed.
	 * @param maxTriesExceeded A reference to a boolean that will be set to true if the maximum
	 * number of tries has been exceeded.
	 * @param letterFound A boolean indicating whether the guessed letter is in the word.
	 * @param letter_ The original letter guessed by the player.
	 * @return A boolean indicating whether the player should keep guessing.
	 */
	bool handle_guess_result(char letter, bool& maxTriesExceeded, bool letterFound, char letter_);

	/**
	 * Sets the difficulty level for the word.
	 *
	 * @param difficulty An enum value of type WordDifficultyTypes indicating the level of difficulty to be set for the word.
	 */
	void setDifficulty(WordDifficultyTypes difficulty);

	/**
	 * Checks if the guessed letter is correct and updates the game state accordingly.
	 *
	 * @param letter The letter guessed by the player.
	 * @return True if the maximum number of tries has been exceeded, false otherwise.
	 */
	bool guessLetter(char letter);

	/**
	 * Checks if the player has won the game.
	 *
	 * This method determines if the player has successfully guessed all the letters in the target word.
	 * Winning conditions are met if all the letters in the target word have been guessed correctly
	 * and there are still attempts left.
	 *
	 * @return true if the player has won the game, false otherwise.
	 */
	[[nodiscard]] bool didWin() const;

	/**
	 * Retrieves the set of letters that have been guessed in the game.
	 *
	 * @return A set containing the letters that have been guessed.
	 */
	std::set<char> getGuessedLetters();

	/**
	 * @brief Prompts the user to decide if they want to play again.
	 *
	 * This method asks the user if they would like to play another game.
	 * If the user indicates 'y', the method starts a new game by calling newGame().
	 * If the user indicates 'n', the application will exit.
	 *
	 * No parameters are required to call this method.
	 *
	 * This method reads input directly from the standard input (e.g., via std::cin)
	 * and thus is blocking; it waits for user input before proceeding.
	 */
	void playAgain();

	/**
	 * Retrieves the number of attempts left in the game.
	 *
	 * @return The number of attempts remaining.
	 */
	[[nodiscard]] int getAttemptsLeft() const;

	/**
	 * @brief Initializes a new game by resetting game state.
	 *
	 * This method clears the guessed letters and incorrect guessed letters,
	 * resets the number of attempts left to the maximum number of tries, and
	 * selects a new target word from the word list.
	 */
	void newGame();
	void decrementAttemptsLeft();

	/**
	 * @brief Retrieves the number of letters in the current target word.
	 *
	 * This method returns the count of characters in the `targetWord`.
	 *
	 * @return The number of letters in the `targetWord`.
	 */
	int getNumberOfLettersInWord() const;
	bool gameOver() const;
	void setName(const std::string& name);
	std::string getTargetWord();

private:
	/**
	 * @brief Manages file operations such as reading, writing, and deleting files.
	 *
	 * The FileManager class encapsulates methods for handling various
	 * file operations. It provides an interface for interacting with the
	 * file system to perform tasks such as creating new files, reading
	 * data from files, writing data to files, and deleting existing files.
	 * This can be used to simplify file access and manipulation within an
	 * application, ensuring consistency and error handling.
	 */
	FileManager file_manager;

	/**
	 * @brief Represents the number of remaining attempts a user has.
	 *
	 * attemptsLeft is initialized to the maximum number of allowable tries,
	 * defined by the constant MAX_NUMBER_TRIES. It is decremented each time
	 * an attempt is made and is used to track how many more attempts are
	 * possible before an action is no longer permitted.
	 */
	int attemptsLeft{MAX_NUMBER_TRIES};

	/**
	 * A set containing the characters that have been guessed by the player.
	 *
	 * This set is used to keep track of all unique letters that the player
	 * has guessed in a game. It helps in checking if a guess has already been made,
	 * and assists in game logic to prevent duplicate guesses.
	 */
	std::set<char> guessedLetters;

	/**
	 * @brief A list of words used in the game.
	 *
	 * This vector holds a collection of words that
	 * are used throughout the game. The list is populated
	 * based on the selected difficulty level and is utilized
	 * to randomly select words for various game functionalities.
	 */
	std::vector<std::string> wordList;

	/**
	 * @brief Pointer to a Player object initialized to nullptr.
	 */
	Player *player{nullptr};

	/**
	 * @brief Represents the current level of a game or application.
	 *
	 * This variable is used to keep track of which level the player or user is currently on.
	 * The value starts at 1 and can increase as the player or user progresses.
	 */
	int level{1};

	/**
	 * @brief A collection of characters representing letters that have been incorrectly guessed by the player.
	 *
	 * This set is used within the game to keep track of all incorrect guesses made by the player. It helps in:
	 * - Displaying the incorrect guesses to the player.
	 * - Determining the state of the hangman graphic.
	 * - Checking if a guessed letter has already been guessed incorrectly.
	 */
	std::set<char> incorrectGuessedLetters{};

	/**
	 * @brief The word that players attempt to guess in the game.
	 *
	 * This variable stores the current word that players are trying to guess.
	 * It is selected randomly from a predefined word list at the start of a new game.
	 * The game logic involves players guessing letters to try to reveal the entire word.
	 * It is used in various functions to check guesses, display the word status,
	 * and determine if the player has won.
	 */
	std::string targetWord{};

	/**
	 * @brief Represents the score in a game or application.
	 *
	 * This integer value is used to keep track of points or
	 * performance metrics. The initial value is set to 0.
	 */
	int score{0};

	/**
	 * Generates a random integer between the specified minimum and maximum values.
	 *
	 * @param min The minimum value that can be generated.
	 * @param max The maximum value that can be generated.
	 * @return A random integer between min and max inclusive.
	 */
	static int generateRandomNumber(int min, int max);

	/**
	 * @brief A vector of strings.
	 *
	 * This variable holds a collection of words.
	 */
	std::vector<std::string> words{};

	/**
	 * @var mutable bool game_state
	 * @brief Represents the current state of the game.
	 *
	 * This variable indicates whether the game is active (true) or inactive (false).
	 * It is mutable, allowing the state to be modified even within const member functions.
	 */
	mutable bool game_state{false};

	std::string name;
};

#endif
