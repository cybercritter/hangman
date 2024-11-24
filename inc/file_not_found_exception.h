#pragma once

#include <exception>
#include <string>

/**
 * @class FileNotFoundException
 * @brief Exception thrown when a file is not found.
 *
 * This exception is typically thrown by file handling operations when
 * the specified file cannot be located.
 */
class FileNotFoundException final : public std::exception {
    /**
     * A string variable to store a message.
     */
private:
    std::string message;

public:
    /**
     * @brief Retrieves a list of words from a file based on the specified difficulty level.
     *
     * This method reads words from the specified file and filters them
     * according to the provided difficulty level.
     *
     * @param difficulty The difficulty level used to filter words.
     * @param fileToRead The path to the file from which words are to be read.
     * @return A vector containing the filtered list of words.
     * @throw FileNotFoundException if the specified file cannot be opened.
     */
    explicit FileNotFoundException(const std::string& filename)
        : message("File not found: " + filename) {}

    /**
     * Returns a C-string representing the error message.
     *
     * Overrides the `what()` method from the standard exception class to provide
     * specific details about the exception.
     *
     * @return A pointer to a null-terminated string with the error message.
     */
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};