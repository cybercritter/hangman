//
// Created by cybercritter on 11/23/24.
//
#include <gtest/gtest.h>
#include <Player.h>

/**
 * @brief Tests the getName method of the Player class.
 *
 * This test checks whether the Player's name is correctly returned by the
 * getName() method. It verifies that the name provided during Player
 * construction is returned accurately.
 *
 * @details
 * The test creates a Player object with the name "mike" and asserts that
 * getName() returns "mike". It also checks that getName() does not return
 * an incorrect name like "bob".
 */
TEST(PlayerTests, getName)
{
    Player give_me_a_name("mike");
    ASSERT_EQ(give_me_a_name.getName(), "mike");  ///< Checks if the name is "mike"
    ASSERT_NE(give_me_a_name.getName(), "bob");  ///< Checks if the name is not "bob"
}

/**
 * @brief Tests the setLevel method of the Player class.
 *
 * This test verifies that the Player's level can be correctly set and
 * retrieved using the setLevel() and getLevel() methods. It ensures
 * that the level is updated properly when set to a new value.
 *
 * @details
 * The test creates a Player object and sets the level to 10 using
 * setLevel(10). It then verifies that getLevel() correctly returns 10.
 * The test also checks that the level is not incorrectly set to another
 * value, such as 20.
 */
TEST(PlayerTests, setLevel)
{
    Player give_me_a_name("mike");  ///< Creates a player named "mike"
    give_me_a_name.setLevel(10);    ///< Sets the player's level to 10
    ASSERT_EQ(give_me_a_name.getLevel(), 10);  ///< Checks if the level is 10
    ASSERT_NE(give_me_a_name.getLevel(), 20);  ///< Checks if the level is not 20
}
