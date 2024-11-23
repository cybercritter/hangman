#include <GameManager.h>

void GameManager::getWordList(FileTypes difficulty) {
	wordList = fm.getWordList(difficulty);
}

int GameManager::calculateScore(std::string &word) {

	return 0;
}

void GameManager::draw() {

}
