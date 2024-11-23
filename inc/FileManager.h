#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <map>
#include <filesystem>
#include <types.h>

namespace fs = std::filesystem;

/**
 * Retrieves word data from the specified file.
 * @param filename The name of the file to read from.
 * @return A vector of strings, each representing a word from the file.
 */
class FileManager {
	/**
	 * @brief A vector of filenames, each as a string.
	 *
	 * This variable holds the list of filenames to be used within the FileManager class.
	 */
private:
    std::map<std::string, int> wordList;
	FileTypes currentDifficulty = FileTypes::EASY_FILE;
    std::filesystem::path filename = fs::current_path() / ".." /"data"/"dictionary.txt";


public:


	/**
	 * Writes high scores to a file.
	 *
	 * @param highScores A pointer to a map that contains player names as keys and their respective high scores as values.
	 */
	static void writeHighScores(std::map<std::string, uint32_t>* highScores);

	/**
	 * Fetches a list of words based on the specified difficulty level.
	 * @param difficulty The difficulty level to filter the words by.
	 */
	[[nodiscard]] std::vector<std::string>  getWordList(FileTypes difficulty) const;
	// Fetches a list of words based on the specified difficulty level.

};

#endif
