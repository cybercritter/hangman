#ifndef WORDMANAGER_H
#define WORDMANAGER_H

#include "FileManager.h"

/**
 * @class WordManager
 * @brief Manages word lists categorized by difficulty.
 */
class WordManager
{
public:
 // ReSharper disable once CppDoxygenUnresolvedReference
 /**
 * Retrieves the list of words based on the specified difficulty level.
 *
 * @param difficulty represents the difficulty level of the words to be retrieved.
  */
 void getWordList(FileTypes difficulty);

 /**
  * @brief Pointer to an instance of FileManager used for file operations.
  */
private:
 FileManager* fileManager = nullptr;

 /**
* @brief Represents the current difficulty level of the file being managed.
*
* The currentDifficulty variable is used within the WordManager class to
* indicate the current difficulty level of the file being worked on.
* This value is of an enumerated type FileManager::FileTypes which defines
* the various difficulty levels or types of files.
*/
 FileTypes currentDifficulty = FileTypes::EASY_FILE;
 /**
  * A map that holds words and their corresponding frequency counts.
  * The key is a string representing the word, and the value is an unsigned 32-bit integer representing the frequency count of that word.
  */
 std::map<std::string, uint32_t> wordList;
};


#endif
