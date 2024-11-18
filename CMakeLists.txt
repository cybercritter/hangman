cmake_minimum_required(VERSION 3.27)

<<<<<<< HEAD
project(hangman LANGUAGES C CXX)
||||||| parent of de9abf1 (update)
project(pointer_discussion LANGUAGES C CXX)
=======
project(cpp_project_starter LANGUAGES C CXX)
>>>>>>> de9abf1 (update)

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
set(CMAKE_SOURCE_DIR_HANGMAN ${CMAKE_SOURCE_DIR}/src)
set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Computer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Player.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/FileManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/WordManager.cpp
        inc/types.h
        inc/FileManager.h
        inc/Computer.h
        inc/IPlayer.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed")
endif()

<<<<<<< HEAD
||||||| parent of de9abf1 (update)
add_executable(${PROJECT_NAME}_CPP ${CMAKE_SOURCE_DIR}/src/main.cpp)

=======
message("CmakeSource Dir ${CMAKE_SOURCE_DIR}")
message("CMake ${PROJECT_BINARY_DIR}")

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)

>>>>>>> de9abf1 (update)
execute_process(COMMAND git log -1 --pretty=format:%h OUTPUT_VARIABLE SHA)

<<<<<<< HEAD
target_compile_definitions(${PROJECT_NAME} PRIVATE "SHA=${SHA}")
target_include_directories(${PROJECT_NAME} PUBLIC "inc")
||||||| parent of de9abf1 (update)
target_compile_definitions(${PROJECT_NAME}_CPP PRIVATE "SHA=${SHA}")
=======
target_compile_definitions(${PROJECT_NAME} PRIVATE "SHA=${SHA}")
>>>>>>> de9abf1 (update)

<<<<<<< HEAD
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
||||||| parent of de9abf1 (update)
# add_subdirectory(src)
install(TARGETS ${PROJECT_NAME}_CPP
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

message("Running Clang Tidy")

find_program(CLANG_TIDY_EXE_NAMES "clang-tidy")
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*")
set_target_properties(${PROJECT_NAME}_CPP PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
=======
# add_subdirectory(src)
install(TARGETS ${PROJECT_NAME}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

message("Running Clang Tidy")

find_program(CLANG_TIDY_EXE_NAMES "clang-tidy")
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*")
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
>>>>>>> de9abf1 (update)

# first we can indicate the documentation build as an option and set it to ON by
# default
option(BUILD_DOCS "Build documentation" ON)

include(Doxygen)
doxygen(src docs)

add_subdirectory(tests)
