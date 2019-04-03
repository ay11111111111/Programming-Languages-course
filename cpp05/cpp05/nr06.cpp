
#include <fstream>
#include <iostream>
#include <random>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"


void test_vector(std::vector<std::string> & vect) {
  std::cout << "vector:" << '\n';
  auto t1 = std::chrono::high_resolution_clock::now();
  vectortest::sort_move(vect);
  auto t2 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> d = (t2 - t1);
  std::cout << "move sorting took " << d.count() << " seconds\n";


  t1 = std::chrono::high_resolution_clock::now();
  vectortest::sort_assign(vect);
  t2 = std::chrono::high_resolution_clock::now();

  d = (t2 - t1);
  std::cout << "assign sorting took " << d.count() << " seconds\n";


  t1 = std::chrono::high_resolution_clock::now();
  vectortest::sort_std(vect);
  t2 = std::chrono::high_resolution_clock::now();

  d = (t2 - t1);
  std::cout << "std sorting took " << d.count() << " seconds\n";
}

void test_list(std::vector<std::string> & vect) {
  std::cout << "list:" << '\n';
  std::list<std::string> list = listtest::from_vector(vect);

  auto t1 = std::chrono::high_resolution_clock::now();
  listtest::sort_move(list);
  auto t2 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> d = (t2 - t1);
  std::cout << "move sorting took " << d.count() << " seconds\n";

  t1 = std::chrono::high_resolution_clock::now();
  listtest::sort_assign(list);
  t2 = std::chrono::high_resolution_clock::now();

  d = (t2 - t1);
  std::cout << "assign sorting took " << d.count() << " seconds\n";

}

int main(int argc, char *argv[])
{
  std::vector<std::string> vect = vectortest::randomstrings(10000, 1500);
  test_vector(vect);
  test_list(vect);
  return 0;
}
