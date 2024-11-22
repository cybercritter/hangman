#include <FileManager.h>

int main(int argc, char *argv[]) {
  const FileManager fm;

  fm.getWordList(FileTypes::EASY_FILE);

  return 0;
}
