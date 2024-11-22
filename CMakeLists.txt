cmake_minimum_required(VERSION 3.27)

project(hangman LANGUAGES C CXX)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Set C++ compiler options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set C compiler options
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SOURCE_DIR_HANGMAN ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(ALL_CXX_SOURCE_FILES
        ${CMAKE_SOURCE_DIR_HANGMAN}/main.cpp
        ${CMAKE_SOURCE_DIR_HANGMAN}/GameManager.cpp
        ${CMAKE_SOURCE_DIR_HANGMAN}/Player.cpp
        ${CMAKE_SOURCE_DIR_HANGMAN}/FileManager.cpp
        ${CMAKE_SOURCE_DIR_HANGMAN}/ScrabbleLetterValueCalculator.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_sources(${PROJECT_NAME} PRIVATE ${ALL_CXX_SOURCE_FILES})

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed")
endif()

target_include_directories(${PROJECT_NAME} PUBLIC "inc")

add_executable(${PROJECT_NAME}_CPP ${CMAKE_SOURCE_DIR}/src/main.cpp)

execute_process(COMMAND git log -1 --pretty=format:%h OUTPUT_VARIABLE SHA)

target_compile_definitions(${PROJECT_NAME} PRIVATE "SHA=${SHA}")
target_include_directories(${PROJECT_NAME} PUBLIC "inc")
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
# add_subdirectory(src)
install(TARGETS ${PROJECT_NAME}_CPP
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

message("Running Clang Tidy")

find_program(CLANG_TIDY_EXE_NAMES "clang-tidy")
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*")
set_target_properties(${PROJECT_NAME}_CPP PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
# add_subdirectory(src)
install(TARGETS ${PROJECT_NAME}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

# first we can indicate the documentation build as an option and set it to ON by
# default
option(BUILD_DOCS "Build documentation" ON)

include(Doxygen)
doxygen(src docs)

add_subdirectory(tests)
