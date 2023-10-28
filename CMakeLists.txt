cmake_minimum_required(VERSION 3.27)

project(cpp_project_starter LANGUAGES C CXX)

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

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed")
endif()

message("CmakeSource Dir ${CMAKE_SOURCE_DIR}")
message("CMake ${PROJECT_BINARY_DIR}")

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)

execute_process(COMMAND git log -1 --pretty=format:%h OUTPUT_VARIABLE SHA)

target_compile_definitions(${PROJECT_NAME} PRIVATE "SHA=${SHA}")

# add_subdirectory(src)
install(TARGETS ${PROJECT_NAME}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

message("Running Clang Tidy")

find_program(CLANG_TIDY_EXE_NAMES "clang-tidy")
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*")
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")

# first we can indicate the documentation build as an option and set it to ON by
# default
option(BUILD_DOC "Build documentation" ON)

include(Doxygen)
doxygen(src docs)

add_subdirectory(tests)
