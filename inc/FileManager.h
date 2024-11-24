#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <map>
#include <filesystem>
#include <types.h>

namespace fs = std::filesystem;

/**
 * @class FileManager
 * @brief Manages operations related to word lists based on difficulty levels.
 *
 * This class is responsible for retrieving word lists from a file
 * based on specified difficulty levels.
 */
class FileManager {

public:
	/**
	 * Retrieves a list of words from a file filtered by the specified difficulty level.
	 *
	 * @param difficulty The difficulty level of the words to retrieve. It determines the length of words
	 *                   that should be included in the returned list.
	 * @param fileToRead Path to the file containing the word list.
	 * @return A vector containing words that match the specified difficulty level.
	 * @throws FileNotFoundException if the specified file cannot be opened.
	 */
	[[nodiscard]] std::vector<std::string>  getWordList(WordDifficultyTypes difficulty, const std::filesystem::path& fileToRead=fs::current_path()/".."/"data" /"dictionary.txt") const;


private:
	/**
	 * A map that associates words with their corresponding counts.
	 *
	 * This data structure is used to store unique words as keys and
	 * their frequency of occurrence as values. It allows for efficient
	 * retrieval, insertion, and removal of words and their associated
	 * counts.
	 *
	 * Key:
	 *    The word represented as a string.
	 * Value:
	 *    The count of occurrences represented as an integer.
	 */
	std::map<std::string, int> wordList;
	/**
	 * @brief Represents the current difficulty level of a word.
	 *
	 * The variable holds the difficulty level of a word, which is used to
	 * categorize words into different levels of difficulty. This is utilized
	 * for generating word lists, quizzes, or games based on difficulty.
	 *
	 * The possible values of WordDifficultyTypes enum representing the difficulty are:
	 * - EASY: Suitable for beginners.
	 * - MEDIUM: Suitable for intermediate users.
	 * - HARD: Suitable for advanced users.
	 *
	 * Example initialization:
	 * - EASY: WordDifficultyTypes::EASY
	 * - MEDIUM: WordDifficultyTypes::MEDIUM
	 * - HARD: WordDifficultyTypes::HARD
	 */
	WordDifficultyTypes currentDifficulty = WordDifficultyTypes::EASY;
	/**
	 * \brief The filename variable holds the path to the dictionary text file.
	 *
	 * This variable uses the filesystem library to dynamically construct the path,
	 * pointing to a file named "dictionary.txt" located in the "data" directory,
	 * which is one level above the current working directory.
	 */
	std::filesystem::path filename = fs::current_path() / ".." /"data"/"dictionary.txt";

};

#endif
