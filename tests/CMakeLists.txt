cmake_minimum_required(VERSION 3.10)

# 'Google_tests' is the subproject name
project(Google_tests)

# Add Google Test subdirectory
add_subdirectory(${CMAKE_SOURCE_DIR}/tests/deps/googletest)

set(CMAKE_SOURCE_DIR_HANGMAN ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_INCLUDE_DIR_HANGMAN ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(ALL_CXX_SOURCE_FILES
        file_manager_test.cpp
)

set(ALL_CXX_INCLUDE_FILES
        ${CMAKE_INCLUDE_CURRENT_DIR_HANGMAN}/../FileManager.h
        ${CMAKE_INCLUDE_CURRENT_DIR_HANGMAN}/../types.h
        ${CMAKE_INCLUDE_CURRENT_DIR_HANGMAN}/../GameManager.h
        ${CMAKE_INCLUDE_CURRENT_DIR_HANGMAN}/../Player.h
        ${CMAKE_INCLUDE_CURRENT_DIR_HANGMAN}/../IPlayer.h
        ${CMAKE_INCLUDE_CURRENT_DIR_HANGMAN}/../file_not_found_exception.h

)

# Google Test include directories
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${ALL_CXX_INCLUDE_FILES})

# Add an executable for the test runner
add_executable(Google_Tests_run
        file_manager_test.cpp
        game_manager_tests.cpp
        player_tests.cpp
)  # Your test source files here

# Link Google Test to your test runner executable
target_link_libraries(Google_Tests_run gtest gtest_main)

target_include_directories(Google_Tests_run PRIVATE "../inc" )
find_library(hangmanlib NAMES hangmanlib)
target_link_libraries(Google_Tests_run GTest::gtest_main)
target_link_libraries(Google_Tests_run hangmanlib)

