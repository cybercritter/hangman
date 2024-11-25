#include <GameManager.h>
#include <iostream>
#include <memory>
#include <random>
#include <Player.h>


/**
 * Destructor for GameManager class.
 * Deallocates the memory assigned to the player and sets the player pointer to null.
 */
GameManager::~GameManager()
{
	delete player;
	player = nullptr;
}

/**
 * Generates a random number within a specified range.
 *
 * @param min The lower bound of the random number range (inclusive).
 * @param max The upper bound of the random number range (inclusive).
 * @return A randomly generated integer between min and max.
 */
int GameManager::generateRandomNumber(const int min, const int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

/**
 * Selects a new target word randomly from the list of available words.
 *
 * This method ensures that the list of words (wordList) is not empty before
 * attempting to select a new word. If the list is empty, an error message is
 * printed and the method exits early to prevent invalid operations.
 */
void GameManager::getNewWord()
{
	// Ensure that wordList is not empty before selecting a random word
	if (wordList.empty())
	{
		std::cerr << "Error: wordList is empty!" << std::endl;
		return; // Early exit if the list is empty
	}

	// Select a random word from the wordList
	targetWord = wordList[generateRandomNumber(0, static_cast<int>(wordList.size()) - 1)];
}

/**
 * Renders the current state of the game to the console.
 * This method displays the hangman, the current word being guessed,
 * incorrect guessed letters, and all guessed letters.
 */
void GameManager::draw() const
{
	displayHangman();

	displayWord();

	std::cout << "Incorrect Guessed Letters: ";
	for (const auto letter : incorrectGuessedLetters)
	{
		std::cout << letter << " ";
	}
	std::cout << std::endl;

	std::cout << "Guessed Letters: ";
	for (const auto letter : guessedLetters)
	{
		std::cout << letter << " ";
	}
	std::cout << std::endl;
}

/**
 * Displays the current state of the target word.
 *
 * This function prints out the target word with guessed letters shown and
 * un-guessed letters represented by underscores. After displaying the word,
 * the function prints a newline.
 */
void GameManager::displayWord() const
{
	for (const auto& letter : targetWord)
	{
		if (guessedLetters.find(letter) != guessedLetters.end())
		{
			std::cout << letter << " "; // Display guessed letter
		}
		else
		{
			std::cout << "_"; // Display underscore for un-guessed letter
		}
	}
	std::cout << std::endl; // End the line after displaying the word
}


/**
 * Displays the current state of the hangman drawing based on the number of incorrect guesses.
 *
 * This method prints the hangman figure to the console, updating its appearance with each incorrect
 * guess. It visually represents the hangman with parts such as the head, body, arms, and legs being added
 * as the number of incorrect guesses increases. Additionally, it shows the number of attempts left.
 *
 * @note The hangman drawing is determined by the size of the `incorrectGuessedLetters` vector.
 */
void GameManager::displayHangman() const
{
	switch(static_cast<int>(incorrectGuessedLetters.size())) {
	case 0:
		std::cout << "  ----\n  |  |\n     |\n     |\n     |\n     |\n=========";
		break;
	case 1:
		std::cout << "  ----\n  |  |\n  O  |\n     |\n     |\n     |\n=========";
		break;
	case 2:
		std::cout << "  ----\n  |  |\n  O  |\n  |  |\n     |\n     |\n=========";
		break;
	case 3:
		std::cout << "  ----\n  |  |\n  O  |\n /|  |\n     |\n     |\n=========";
		break;
	case 4:
		std::cout << "  ----\n  |  |\n  O  |\n /|\\ |\n     |\n     |\n=========";
		break;
	case 5:
		std::cout << "  ----\n  |  |\n  O  |\n /|\\ |\n /   |\n     |\n=========";
		break;
	case 6:
		std::cout << "  ----\n  |  |\n  O  |\n /|\\ |\n / \\ |\n     |\n=========";
		break;
	default:
		std::cout << "Invalid number of incorrect guesses.";
		break;
	}
	std::cout << std::endl << "Attempts Left: " << attemptsLeft << std::endl;
}

/**
 * Starts a new game of Hangman.
 *
 * This method welcomes the player, prompts them to enter their name,
 * creates a new Player instance with the provided name, and begins a new game.
 *
 * It outputs a welcome message and a personalized game creation message.
 *
 * @note This method handles user input and standard output operations.
 */
void GameManager::start()
{


	std::cout << "Select Difficulty: " << std::endl;
	std::cout << "1. Easy" << std::endl;
	std::cout << "2. Medium" << std::endl;
	std::cout << "3. Hard" << std::endl;

	int difficulty;
	std::cin >> difficulty;

	wordList = file_manager.getWordList(static_cast<WordDifficultyTypes>(difficulty));
	getNewWord();

	player = new Player(name);
	std::cout << "Creating a new game for you " << player->getName() << std::endl;
}

/**
 * Prompts the player to guess a letter and processes the input.
 *
 * This function outputs a message asking the player to guess a letter, reads the input,
 * converts the letter to lowercase, and then checks if the guessed letter is correct.
 */
void GameManager::menu()
{
	char letter;
	std::cout << std::endl;
	std::cout << player->getName();
	std::cout << " Please guess a letter: ";
	std::cin >> letter;

	letter = static_cast<char>(tolower(letter));

	guessLetter(letter);
}

/**
 * Handles the result of a guessed letter in the game.
 * Determines whether the guessed letter is in the word, updates guessed and incorrect letter collections,
 * and manages remaining attempts.
 *
 * @param letter The letter that was guessed.
 * @param maxTriesExceeded A reference to a bool that will be set to true if the maximum number of allowed tries is exceeded.
 * @param letterFound Indicates whether the guessed letter was found in the word.
 * @param letter_ The letter to be inserted into the incorrect guessed letters collection if the guess is wrong.
 */
bool GameManager::handle_guess_result(const char letter, bool& maxTriesExceeded, const bool letterFound,
                                      const char letter_)
{
	bool keepGuessing = true;

	// Handle the result of the guess
	if (letterFound)
	{
		std::cout << "Good guess! The letter '" << letter << "' is in the word!" << std::endl;
	}
	else
	{
		std::cout << "Incorrect guess!" << std::endl;
		incorrectGuessedLetters.insert(letter_); // Add to incorrectGuessedLetters


		if (attemptsLeft > 0 && attemptsLeft <= MAX_NUMBER_TRIES)
		{
			decrementAttemptsLeft();
		}
		else
		{
			maxTriesExceeded = true;
			keepGuessing = false;
		}
	}
	guessedLetters.insert(letter); // Add to guessedLetters only if the guess is correct
	return keepGuessing;
}

/**
 * Handles the guessing of a letter in the game.
 *
 * @param letter The letter being guessed by the player.
 * @return true if the maximum number of tries have been exceeded after the guess, otherwise false.
 */
bool GameManager::guessLetter(const char letter)
{
	bool maxTriesExceeded = false;
	// Flag to check if the letter is in the target word
	bool letterFound = false;

	// make the letter case-insensitive

	// Check if the letter has already been guessed correctly or incorrectly
	if (const char letter_ = static_cast<char>(tolower(letter));
		guessedLetters.find(letter_) != guessedLetters.end())
	{
		std::cout << "You already guessed the letter '" << letter << "'." << std::endl;
	}
	else
	{
		// If the letter is incorrect and not already guessed incorrectly
		if (incorrectGuessedLetters.find(letter_) != incorrectGuessedLetters.end())
		{
			std::cout << "The letter '" << letter_ << "' has already been guessed incorrectly." << std::endl;
		}
		else
		{
			// Iterate over the target word to check if the letter is present
			for (const auto& letter_s : targetWord)
			{
				if (letter_s == letter_)
				{
					letterFound = true;
					break;
				}
			}

			handle_guess_result(letter, maxTriesExceeded, letterFound, letter_);
		}
	}

	return (maxTriesExceeded || letterFound);
}


/**
 * Checks if the player has won the game.
 *
 * @return True if the player has successfully guessed all letters in the target word before
 * using all attempts, false otherwise.
 */
bool GameManager::didWin() const
{
	// If there are no attempts left, player loses
	if (this->attemptsLeft == 0)
	{
		this->game_state = true;
		return false;
	}

	// Check if every letter in targetWord has been guessed
	for (const auto& c : targetWord)
	{
		if (guessedLetters.find(c) == guessedLetters.end())
		{
			return false;
		}
	}

	// If all letters have been guessed, player wins
	this->game_state = true;
	return true;
}

/**
 * Retrieves the number of attempts left for the game.
 *
 * @return The number of remaining attempts.
 */
int GameManager::getAttemptsLeft() const
{
	return attemptsLeft;
}

/**
 * Starts a new game by resetting the guessed letters, incorrect guessed letters,
 * setting the number of attempts left to the maximum allowed, and retrieving a new word.
 */
void GameManager::newGame()
{
	guessedLetters.clear();
	incorrectGuessedLetters.clear();
	attemptsLeft = MAX_NUMBER_TRIES;
	getNewWord();
	game_state = false;
}

/**
 * Decrements the number of attempts left by one.
 *
 * @return The updated number of attempts left after decrement.
 */
void GameManager::decrementAttemptsLeft()
{
	attemptsLeft--;
}

/**
 * Retrieves the set of guessed letters.
 *
 * @return A set containing characters that have been guessed.
 */
std::set<char> GameManager::getGuessedLetters()
{
	return guessedLetters;
}

/**
 * Prompts the user to decide whether to play again or exit the game.
 * Reads user input and starts a new game if the response is not 'n'
 * (case-insensitive); otherwise, terminates the program.
 */
void GameManager::playAgain()
{
	// Logic to read user input (e.g., using std::cin or event handling)
	// Example for console-based input:
	char input;
	std::cout << "Play again? [y,n]): ";
	std::cin >> input;

	input = static_cast<char>(tolower(input));
	if (input != 'n')
	{
		newGame();
		start();
	}
	else
	{
		std::cout << "Thanks for playing! Exiting the game..." << std::endl;
		std::exit(EXIT_SUCCESS);
	}
}

/**
 * @brief Retrieves the number of letters in the current target word.
 *
 * This method returns the count of characters in the `targetWord`.
 *
 * @return The number of letters in the `targetWord`.
 */
int GameManager::getNumberOfLettersInWord() const
{
	return static_cast<int>(targetWord.length());
}


/**
 * Checks if the game is over.
 * @return True if the game is over, otherwise false.
 */
bool GameManager::gameOver() const
{
	return game_state;
}

void GameManager::setName(const std::string& name_)
{
	name = name_;
}

std::string GameManager::getTargetWord()
{
	return targetWord;
}

