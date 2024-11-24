#include <FileManager.h>
#include <fstream>
#include <string>
#include <vector>
#include <file_not_found_exception.h>
#include <iostream>

/**
 * Retrieves a list of words from a specified file filtered by the given difficulty level.
 *
 * @param difficulty The difficulty level used to filter the words. It can be one of the following:
 *        - WordDifficultyTypes::EASY: Only includes words with a length up to EASY_FILE_MAX_LENGTH.
 *        - WordDifficultyTypes::MEDIUM: Includes words with a length greater than EASY_FILE_MAX_LENGTH
 *										 and up to MEDIUM_FILE_MAX_LENGTH.
 *        - WordDifficultyTypes::HARD: Includes words with a length greater than MEDIUM_FILE_MAX_LENGTH
 *									   and up to HARD_FILE_MAX_LENGTH.
 * @param fileToRead The file path from which the words are read.
 *
 * @return A vector containing words that match the specified difficulty level.
 *
 * @throws FileNotFoundException if the specified file cannot be opened.
 */
std::vector<std::string> FileManager::getWordList(WordDifficultyTypes difficulty,
                                                  const std::filesystem::path &fileToRead) const
{
	std::ifstream file(fileToRead);
	std::vector<std::string> wordList;

	// Ensure the file is successfully opened
	if (!file.is_open()) {
		throw FileNotFoundException(fileToRead);  // Corrected to use fileToRead
	}

	// Lambda function to determine if a word should be included based on the difficulty level
	auto shouldIncludeWord = [difficulty](const std::string& word) -> bool {
		size_t wordLength = word.length();
		switch (difficulty) {
		case WordDifficultyTypes::EASY:
			return wordLength <= EASY_FILE_MAX_LENGTH;
		case WordDifficultyTypes::MEDIUM:
			return wordLength > EASY_FILE_MAX_LENGTH && wordLength <= MEDIUM_FILE_MAX_LENGTH;
		case WordDifficultyTypes::HARD:
			return wordLength > MEDIUM_FILE_MAX_LENGTH && wordLength <= HARD_FILE_MAX_LENGTH;
		default:
			return false;  // Default case, should never happen if difficulty is properly validated
		}
	};

	// Read words from the file and filter them based on difficulty
	for (std::string word; std::getline(file, word);) {
		if (shouldIncludeWord(word)) {
			wordList.push_back(word);
		}
	}

	file.close();

	std::cout << "word list size " << wordList.size() << std::endl;

	return wordList;
}


