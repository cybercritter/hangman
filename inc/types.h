//
// Created by cybercritter on 11/17/24.
//

#ifndef TYPES_H
#define TYPES_H

#include <map>

/**
 * @enum WordDifficultyTypes
 * @brief An enumeration to represent the difficulty levels of words.
 *
 * This enum class provides three different difficulty levels for words:
 * - EASY: Represents words that are easy to guess.
 * - MEDIUM: Represents words that have medium difficulty in guessing.
 * - HARD: Represents words that are hard to guess.
 *
 * Each difficulty level is associated with an integer value, which can indicate,
 * for example, the number of attempts a player may have to guess the word.
 */
enum class WordDifficultyTypes {
    EASY = 1,
    MEDIUM = 2,
    HARD = 3
};


/**
 * @brief Defines the maximum length for words in the 'EASY' difficulty category.
 *
 * This constant is used to filter words based on their length when classifying them
 * as 'EASY' in the context of word difficulty levels. Only words whose length is
 * less than or equal to this value are considered 'EASY'.
 *
 * @see WordDifficultyTypes::EASY
 */
constexpr unsigned int EASY_FILE_MAX_LENGTH = 5;
/**
 * @brief Maximum allowable length for words categorized as MEDIUM difficulty.
 *
 * This constant is used by the FileManager class to filter out words based on predefined length criteria,
 * specifically those whose lengths classify them as being of MEDIUM difficulty.
 * It is derived from the MEDIUM difficulty type enumeration.
 */
constexpr unsigned long MEDIUM_FILE_MAX_LENGTH = 7;
/**
 * @brief Maximum allowable length for words classified as "HARD" difficulty.
 *
 * This constant defines the upper bound on the length of words that are
 * considered to be of "HARD" difficulty. Any word with a length greater
 * than this value will not be classified as "HARD".
 *
 * @ingroup Config
 */
constexpr unsigned long HARD_FILE_MAX_LENGTH = 10;


/**
 * @brief The maximum allowed length for a file name, including the null terminator.
 *
 * This constant defines the upper limit for the number of characters in a file name.
 * The value includes space for the null terminator, making the effective maximum length
 * for the file name itself 254 characters. This limit ensures compatibility with most
 * file systems which have a maximum file name length restriction.
 */
constexpr int MAX_FILE_NAME_LENGTH = 255;

/**
 * @brief Specifies the maximum number of attempts allowed for guessing letters in the game.
 *
 * This constant is used in the game logic to determine the maximum number of incorrect guesses a player is allowed.
 * If the number of incorrect guesses exceeds this value, specific game actions are triggered, such as ending the game
 * or notifying the player of failure.
 */
constexpr int MAX_NUMBER_TRIES = 6;

/**
 * @brief Maximum number of words that can be read.
 *
 * This constant defines the upper limit on the number of words that can be read in a single operation.
 * It is set to 250, which may be used as a threshold to control the data processing limits.
 */
constexpr int MAX_NUMBER_WORDS_READ = 250;




#endif
