#include <iostream>
#include <map>
#include <string>
#include <algorithm>

// Scrabble letter values
std::map<char, int> scrabbleValues = {
    {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1}, {'F', 4},
    {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8}, {'K', 5}, {'L', 1},
    {'M', 3}, {'N', 1}, {'O', 1}, {'P', 3}, {'Q', 10},{'R', 1},
    {'S', 1}, {'T', 1}, {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8},
    {'Y', 4}, {'Z', 10}
};

int calculateWordValue(const std::string& word) {
    int totalValue = 0;
    for (char c : word) {
        char upperChar = std::toupper(c);
        if (scrabbleValues.find(upperChar) != scrabbleValues.end()) {
            totalValue += scrabbleValues[upperChar];
        } else {
            std::cerr << "Invalid character '" << c << "' in word." << std::endl;
            return -1; // Return -1 to indicate an error
        }
    }
    return totalValue;
}

int returnLetterValue(char letter) {
  int letterValue = 0;
  if(auto value = scrabbleValues.find(letter); value != scrabbleValues.end()) {
        letterValue = value->second;
  }else
  {
    letterValue = 0;
  }

  return letterValue;
}