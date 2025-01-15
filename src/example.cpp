#include <cstdlib>
#include <csv2/reader.hpp>
#include <filesystem>
#include <iostream>
#include <strings.h>

int main(int argc, char *argv[]) {
  const auto home_path = std::getenv("HOME");
  if (!home_path) {
    std::cerr << "Unable to locate home directory!" << std::endl;
  }

  csv2::Reader reader;
  if (reader.mmap(std::string(home_path) + "/some_file.csv")) {
    for (const auto &row : reader) {
      std::cout << "row:\n";
      for (const auto &cell : row) {
        std::string value;
        cell.read_value(value);
        std::cout << value << ", ";
      };
      std::cout << "\n";
    }
  }
  return 0;
}
