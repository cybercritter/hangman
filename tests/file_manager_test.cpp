//
// Created by cybercritter on 11/23/24.
//
#include <FileManager.h>
#include <gtest/gtest.h>
#include <file_not_found_exception.h>
#include <fstream>

/**
 * @brief Tests the `getWordList` method with the "EASY" difficulty level.
 *
 * This test checks whether the `getWordList` method correctly filters and
 * retrieves words for the "EASY" difficulty level. It ensures that the
 * returned word list contains the expected number of words and specific words
 * at certain indices.
 *
 * @details
 * - Verifies that the returned word list has 49 words for the "EASY" difficulty.
 * - Checks specific words at certain indices (0, 26, 48).
 * - Ensures that an unexpected word ("Homer") is not present in the list.
 */
TEST(FileManagerTest, getWordListEasy)
{
    const FileManager fm;
    const std::vector<std::string> words = fm.getWordList(WordDifficultyTypes::EASY);

    ASSERT_EQ(words.size(), 49);        ///< Verifies the number of words is correct.
    ASSERT_EQ(words[0], "Abate");       ///< Verifies the first word is "Abate".
    ASSERT_EQ(words[26], "The");       ///< Verifies the word at index 26 is "The".
    ASSERT_EQ(words[48], "Yield");     ///< Verifies the last word is "Yield".
    ASSERT_NE(words[0], "Homer");      ///< Verifies "Homer" is not in the word list.
}

/**
 * @brief Tests the `getWordList` method with the "MEDIUM" difficulty level.
 *
 * This test checks whether the `getWordList` method correctly filters and
 * retrieves words for the "MEDIUM" difficulty level. It ensures that the
 * returned word list contains the expected number of words and specific words
 * at certain indices.
 *
 * @details
 * - Verifies that the returned word list has 66 words for the "MEDIUM" difficulty.
 * - Checks specific words at certain indices (0, 26, 65).
 * - Ensures that an unexpected word ("Stalin") is not present in the list.
 */
TEST(FileManagerTest, getWordListMedium)
{
    const FileManager fm;
    const std::vector<std::string> words = fm.getWordList(WordDifficultyTypes::MEDIUM);

    ASSERT_EQ(words.size(), 66);        ///< Verifies the number of words is correct.
    ASSERT_EQ(words[0], "Abysmal");    ///< Verifies the first word is "Abysmal".
    ASSERT_EQ(words[26], "Disdain");   ///< Verifies the word at index 26 is "Disdain".
    ASSERT_EQ(words[65], "Warrant");   ///< Verifies the last word is "Warrant".
    ASSERT_NE(words[0], "Stalin");     ///< Verifies "Stalin" is not in the word list.
}

/**
 * @brief Tests the `getWordList` method with the "HARD" difficulty level.
 *
 * This test checks whether the `getWordList` method correctly filters and
 * retrieves words for the "HARD" difficulty level. It ensures that the
 * returned word list contains the expected number of words and specific words
 * at certain indices.
 *
 * @details
 * - Verifies that the returned word list has 106 words for the "HARD" difficulty.
 * - Checks specific words at certain indices (0, 53, 105).
 * - Ensures that an unexpected word ("Vicodin") is not present in the list.
 */
TEST(FileManagerTest, getWordListHard)
{
    const FileManager fm;
    const std::vector<std::string> words = fm.getWordList(WordDifficultyTypes::HARD);

    ASSERT_EQ(words.size(), 106);       ///< Verifies the number of words is correct.
    ASSERT_EQ(words[0], "Abstract");   ///< Verifies the first word is "Abstract".
    ASSERT_EQ(words[53], "Imposing");  ///< Verifies the word at index 53 is "Imposing".
    ASSERT_EQ(words[105], "Viability");///< Verifies the last word is "Viability".
    ASSERT_NE(words[0], "Vicodin");    ///< Verifies "Vicodin" is not in the word list.
}

/**
 * @brief Tests the `getWordList` method when the file is invalid or not found.
 *
 * This test checks whether the `getWordList` method properly throws a
 * `FileNotFoundException` when trying to load a non-existent or invalid file.
 *
 * @details
 * - Attempts to load a file located at "../test_files/invalid_word_list.txt".
 * - Asserts that the `FileNotFoundException` is thrown when the file cannot be found.
 */
TEST(FileManagerTest, getWordListInvalid)
{
    const FileManager fm;
    ASSERT_THROW(
        std::vector<std::string> d = fm.getWordList(WordDifficultyTypes::HARD, R"(../test_files/invalid_word_list.txt)"),
        FileNotFoundException); ///< Verifies that a FileNotFoundException is thrown.
}
