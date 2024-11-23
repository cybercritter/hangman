//
// Created by cybercritter on 11/17/24.
//

#ifndef TYPES_H
#define TYPES_H


/**
 * @enum FileTypes
 * @brief Enumerates different types of word files.
 *
 * This enumeration defines various categories of file types
 * Easy, medium and hard words to guess.
 */
enum class FileTypes {
    EASY_FILE = 5,
    MEDIUM_FILE = 7,
    HARD_FILE = 10
};

constexpr unsigned int EASY_FILE_MAX_LENGTH = static_cast<unsigned int>(FileTypes::EASY_FILE);
constexpr unsigned long MEDIUM_FILE_MAX_LENGTH = static_cast<unsigned long>(FileTypes::MEDIUM_FILE);
constexpr unsigned long HARD_FILE_MAX_LENGTH = static_cast<unsigned long>(FileTypes::HARD_FILE);


/**
 * @brief Defines the maximum allowable length for a file name.
 *
 * This constant specifies the maximum number of characters
 * that a file name can contain, including the null terminator.
 * It is used to ensure that file names do not exceed the
 * length limit imposed by the filesystem or application logic.
 */
constexpr int MAX_FILE_NAME_LENGTH = 255;

/**
 * @brief The maximum number of attempts allowed for a user to complete the word guess
 * before the hangman is complete.
 */
constexpr int MAX_NUMBER_TRIES = 6;

/**
 * @brief Defines the maximum number of words that can be read in from a file.
 * It is used to prevent buffer overflows and ensure
 * efficient data handling.
 */
constexpr int MAX_NUMBER_WORDS_READ = 60;




#endif
