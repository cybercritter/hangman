#include <GameManager.h>
#include <iostream>


/**
 * The entry point of the application.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return An integer representing the exit status of the program.
 */
int main(int argc, char *argv[]) {
  // Create a GameManager instance with a specific difficulty
  const auto gameManager = std::make_unique<GameManager>();
  std::string name_;
  std::cout << "Welcome to Hangman - the classic word guessing game" << std::endl;
  std::cout << "Apologize for being personal but what is your name? ";
  std::cin >> name_;
  std::cout << std::endl;

  gameManager->start();

  // Main game loop
for (;;)
{
  gameManager->setPlayerName(name_);
  gameManager->draw();   // Draw the game state
  gameManager->menu();   // Show the menu for input (e.g., player guesses)

  // Check if the player has won
  if (gameManager->didWin()) {
    std::cout << "You win! You guessed the word - " << gameManager->getTargetWord()  << std::endl;
  }
  if (gameManager->getAttemptsLeft() == 0) {
    std::cout << "You lose! The word was - " << gameManager->getTargetWord() << std::endl;
  }

  if (gameManager->gameOver())
  {
    gameManager->playAgain();  // Ask if the player wants to play again
  }
}

  // unreachable code - the clang tidy static analyzer errors if main is void
  return 0;
}
