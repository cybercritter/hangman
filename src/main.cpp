#include <iostream>
#include <string>

/**
 * @class Dummy
 * @brief This is a dummy class that just prints a message
 */
class Dummy {
 public:
  Dummy() = default;
  ~Dummy() = default;

  /**
   * @brief Print a stupid message
   */
  void print_dummy() const {
    std::cout << "Printing Dummy data: " << data << std::endl;
  }

 private:
  /**
   * @brief store the dummy message
   */
  std::string data{"Are you kidding"};
};

int main(int argc, char *argv[]) {
  Dummy dummy;

  dummy.print_dummy();
}
