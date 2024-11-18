#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <map>

#include <types.h>

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
	std::vector<std::string> filename;

	/**
	 * Retrieves the word data from a file.
	 *
	 * @param filename The name of the file from which to read the word data.
	 * @return A vector of strings containing the words read from the file.
	 */
public:
	std::vector<std::string> getWordData(std::string filename);

	/**
	 * Writes high scores to a file.
	 *
	 * @param highScores A pointer to a map that contains player names as keys and their respective high scores as values.
	 */
	void writeHighScores(std::map<std::string, uint32_t>* highScores);

};

#endif
