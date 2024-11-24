//
// Created by cybercritter on 11/23/24.
//

#include <gtest/gtest.h>
#include <GameManager.h>

const std::vector<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};

bool guessAnyVowel(GameManager &gm, const std::vector<char> &vowels) {
    for (const char vowel : vowels) {
        if (gm.guessLetter(vowel)) {
            return true;
        }
    }
    return false;
}

TEST(GameManagerTest, guessTest)
{
    GameManager gm(WordDifficultyTypes::EASY);
    const bool isVowelGuessed = guessAnyVowel(gm, VOWELS);
    ASSERT_TRUE(isVowelGuessed);
}

TEST(GameManagerTest, guessTestTooManyGuesses)
{
    GameManager gm(WordDifficultyTypes::EASY);
    const int size = gm.getNumberOfLettersInWord();
    for (int i = 0; i < size+1; i++) {
        gm.guessLetter('a');
    }
    ASSERT_FALSE(gm.guessLetter('a'));
    ASSERT_EQ(gm.getAttemptsLeft(), 0);
    ASSERT_NE(gm.getAttemptsLeft(), -1);
}

TEST(GameManagerTest, guessTestBad)
{
    GameManager gm(WordDifficultyTypes::EASY);

    ASSERT_FALSE(gm.guessLetter('z'));
}