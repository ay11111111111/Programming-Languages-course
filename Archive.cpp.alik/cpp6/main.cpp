
#include <fstream>
#include <iostream>
#include <random>

#include "vectortest.h"
#include "maptest.h"
#include "unordered_maptest.h"

// #include "timer.h"


int main(int argc, char *argv[])
{
  std::ifstream inp{ "test_input.txt" };

  // std::vector<std::string> vect = vectortest::readfile(inp);
  std::vector<std::string> vect = { "AA", "aA", "Aa", "this", "THIS" };


  std::cout << "-------------------------------\n";
  std::cout << "              VECT:            \n";
  std::cout << vect << "\n";
  std::cout << "-------------------------------\n";
  std::cout << "\n\n";

  auto u_cnt = unordered_maptest::frequencytable(vect);
  std::cout << "-------------------------------\n";
  std::cout << "             U_CNT:            \n";
  std::cout << u_cnt;
  std::cout << "-------------------------------\n";
  std::cout << "\n\n";

  auto cnt = maptest::frequencytable(vect);
  std::cout << "-------------------------------\n";
  std::cout << "              CNT:             \n";
  std::cout << cnt;
  std::cout << "-------------------------------\n";
  std::cout << "\n\n";

  case_insensitive_hash h;
  std::cout << "-------------------------------\n";
  std::cout << "              HASH:            \n";
  std::cout << h("xxx") << " " << h("XXX") << "\n";
  std::cout << h("Abc") << " " << h("abC") << "\n";
  std::cout << "-------------------------------\n";
  std::cout << "\n\n";

  // Hash value should be case insensitive.

  std::cout << "-------------------------------\n";
  std::cout << "              H(S):            \n";

  for (auto s: vect) std::cout << s << " " << h(s) << "\n";
  std::cout << "-------------------------------\n";
  std::cout << "\n\n";

  case_insensitive_equality e;
  std::cout << "-------------------------------\n";
  std::cout << "              EQL:             \n";
  std::cout << e("xxx", "XXX") << "\n";
  std::cout << e("a", "A") << e("a", "b") << e("A", "b") << "\n";
  std::cout << "-------------------------------\n";
  std::cout << "\n\n";

  std::cout << "-------------------------------\n";
  std::cout << "              E(S):            \n";
  for (size_t i = 0; i < vect.size(); i++)
    for (size_t j = i + 1; j < vect.size(); j++) {
      std::cout << vect[i] << " " << vect[j] << " ";
      std::cout << e(vect[i], vect[j]) << " " << e(vect[j], vect[i]) << "\n";
    }
  std::cout << "-------------------------------\n";
  std::cout << "\n\n";
  return 0;
}
