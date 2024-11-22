#pragma once

#include <exception>
#include <string>

class FileNotFoundException final : public std::exception {
private:
    std::string message;
public:
    explicit FileNotFoundException(const std::string& filename)
        : message("File not found: " + filename) {}

    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};