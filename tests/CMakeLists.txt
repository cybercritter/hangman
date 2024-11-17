enable_testing()
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/v1.15.2.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(hangman_test hangman_test.cpp)
target_link_libraries(hangman_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(hangman_test)

target_include_directories(${PROJECT_NAME} PUBLIC "inc")
