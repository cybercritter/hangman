#include <FileManager.h>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <file_not_found_exception.h>

/**
 * Retrieves a list of words from a file based on the given difficulty level.
 *
 * @param difficulty The difficulty level, represented by the FileTypes enum, which determines the required word length.
 * @throws FileNotFoundException if the file specified by filename cannot be opened.
 * @return A vector of strings containing words that match the specified difficulty level.
 */
#include <iostream>
std::vector<std::string> FileManager::getWordList(FileTypes difficulty) const
{
	std::ifstream file(filename);
	std::vector<std::string> wordList;

	if (!file.is_open())
	{
		throw FileNotFoundException(filename);
	}

	auto shouldIncludeWord = [difficulty](const std::string& word) -> bool {
		switch (difficulty) {
		case FileTypes::EASY_FILE: return word.length() <= EASY_FILE_MAX_LENGTH;
		case FileTypes::MEDIUM_FILE: return word.length() > EASY_FILE_MAX_LENGTH && word.length() <= MEDIUM_FILE_MAX_LENGTH;
		case FileTypes::HARD_FILE: return word.length() > MEDIUM_FILE_MAX_LENGTH && word.length() <= HARD_FILE_MAX_LENGTH;
		default: return true;
		}
	};

	for (std::string word; std::getline(file, word);) {
		if (shouldIncludeWord(word)) {
			wordList.push_back(word);
		}
	}

	return wordList;
}
	/**
	 * Writes the high scores to a text file named "highscores.txt".
	 *
	 * @param highScores A pointer to a map containing player names and their corresponding scores.
	 */
	void FileManager::writeHighScores(std::map<std::string, uint32_t>* highScores)
	{
		std::fstream file;
		file.open("highscores.txt", std::ios::out | std::ios::trunc);

		for (auto& [player, score] : *highScores)
		{
			file << player << " " << score << std::endl;
		}
		file.close();
	}
