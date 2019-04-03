
#include <fstream>
#include <iostream>
#include <random>


#include "vectortest.h"
#include "maptest.h"
#include "unordered_maptest.h"

int main() {
  std::ifstream file("confessiones-book1.txt");
  auto book                      = vectortest::readfile(file);
  auto table                     = unordered_maptest::frequencytable(book);
  std::vector<std::string> words = { "magnus", "hominum", "memoria" };

  for (auto s: words) {
    std::cout << s << " occurs " << table[s] << " times" << "\n";
  }
  auto frequent = unordered_maptest::most_frequent(table);

  if (frequent == table.end()) {
    std::cout << "Table is empty";
  } else {
    std::cout << frequent->first << " occured " << frequent->second << " times" <<
    "\n";
  }
}
