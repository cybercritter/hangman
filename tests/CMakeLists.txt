enable_testing()
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/v1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(cpp_pointers_test cpp_pointers_test.cpp)
target_link_libraries(cpp_pointers_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(cpp_pointers_test)

# target_include_directories()
