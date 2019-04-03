
#include <fstream>
#include <iostream>
#include <random>

#include "listtest.h"
#include "vectortest.h"

// #include "timer.h"


int main(int argc, char *argv[])
{
  std::ifstream input_file{ "test.txt" };
  std::vector<std::string> vect = vectortest::readfile(input_file);

  std::cout << vect << "\n";

//  std::list<std::string> list = { "123", "456", "2" };
//  std::cout << list << "\n";

//  list.pop_back();
//  std::cout << list << "\n";

//  list.pop_front();
//  std::cout << list << "\n";

//  list.pop_back();
//  std::cout << list << "\n";
  return 0;
}
