#include <FileManager.h>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <file_not_found_exception.h>/**
 * Retrieves a list of words from a file based on the given difficulty level.
 *
 * @param difficulty The difficulty level, represented by the FileTypes enum, which determines the required word length.
 * @throws FileNotFoundException if the file specified by filename cannot be opened.
 * @return A vector of strings containing words that match the specified difficulty level.
 */
#include <iostream>

void FileManager::getWordList(FileTypes difficulty) const
{
	auto file = std::ifstream(filename);
	unsigned long wordSize = 0;
	if (!file.is_open())
	{
		throw FileNotFoundException(filename);
	}

	std::vector<std::string> wordList;

	switch (difficulty)
	{
	case FileTypes::EASY_FILE:
		wordSize = 5;
		break;

	case FileTypes::MEDIUM_FILE:
		wordSize = 7;
		break;
	case FileTypes::HARD_FILE:
		wordSize = 9;
		break;

	default:
		wordSize = 0;
		break;
	}
	for (std::string word; std::getline(file, word);)
	{
		if (word.length() == static_cast<unsigned long>(difficulty))
		{
			if (word.length() <= wordSize )
				wordList.push_back(word);
		}
	}

	file.close();

	for (const auto& word : wordList)
	{
		std::cout << word << std::endl;
	}
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
		file.clear();
		file << player << " " << score << std::endl;
	}
	file.close();
}
