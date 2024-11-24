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

# Set the data directory name
set(DATA_DIR "${CMAKE_BINARY_DIR}/data")

# Create the data directory if it doesn't exist
if(NOT EXISTS "${DATA_DIR}")
    file(MAKE_DIRECTORY "${DATA_DIR}")
endif()
configure_file("data/dictionary.txt" "${CMAKE_BINARY_DIR}/data/" COPYONLY)

# set all source files
set(CMAKE_SOURCE_DIR_HANGMAN ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(ALL_CXX_SOURCE_FILES
        ${CMAKE_SOURCE_DIR_HANGMAN}/main.cpp
        ${CMAKE_SOURCE_DIR_HANGMAN}/GameManager.cpp
        ${CMAKE_SOURCE_DIR_HANGMAN}/Player.cpp
        ${CMAKE_SOURCE_DIR_HANGMAN}/FileManager.cpp
)

#build library
message("Building library")
add_library(${PROJECT_NAME}lib ${ALL_CXX_SOURCE_FILES})
target_include_directories(${PROJECT_NAME}lib PRIVATE "inc")

# Build binary
message("Building Application")

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "inc")
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}lib)

# first we can indicate the documentation build as an option and set it to ON by
# default
option(BUILD_DOCS "Build documentation" ON)
include(Doxygen)
doxygen(src docs)

# build tests
add_subdirectory(tests)
