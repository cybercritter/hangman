cmake_minimum_required(VERSION 3.27)

project(cpp_project_starter LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Set C++ compiler options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# # Set C compiler options
# set(CMAKE_C_STANDARD 11)
# set(CMAKE_C_STANDARD_REQUIRED ON)
# set(CMAKE_C_EXTENSIONS OFF)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SOURCE_DIR_STARTER ${CMAKE_SOURCE_DIR}/src)
file(GLOB_RECURSE
  ALL_CXX_SOURCE_FILES
  ${CMAKE_SOURCE_DIR_STARTER}/*.[chi]pp
  ${CMAKE_SOURCE_DIR_STARTER}/*.[chi]xx
  ${CMAKE_SOURCE_DIR_STARTER}/*.cc
  ${CMAKE_SOURCE_DIR_STARTER}/*.hh
  ${CMAKE_SOURCE_DIR_STARTER}/*.ii
  ${CMAKE_SOURCE_DIR_STARTER}/*.[CHI]
)

add_executable(${PROJECT_NAME} ${ALL_CXX_SOURCE_FILES})

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed")
endif()

execute_process(COMMAND git log -1 --pretty=format:%h OUTPUT_VARIABLE SHA)

target_compile_definitions(${PROJECT_NAME} PRIVATE "SHA=${SHA}")

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

# first we can indicate the documentation build as an option and set it to ON by
# default
option(BUILD_DOCS "Build documentation" ON)

include(Doxygen)
doxygen(src docs)

add_subdirectory(tests)
