
#include <fstream>
#include <iostream>
#include <random>

//#include "listtest.h"
#include "vectortest.h"
#include "timer.h"
/*
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
*/
auto
max_freq(const std::map <std::string, unsigned int, case_insensitive_cmp>& freq)
{
  std::pair<std::string, unsigned int> max;
  for (auto pair : freq) {
      if(pair.second > max.second){
        max = pair;
      }
  }
  return max;
}


int main(int argc, char *argv[])
{
    std::vector<std::string> vect = vectortest::randomstrings(10000, 1500);
  //  test_vector(vect);
  //  test_list(vect);

    std::ifstream file ("text.txt");
    std::vector<std::string> book = vectortest::readfile(file);
    std::cout << "First Test: ";
    std::cout << frequency_table( std::vector< std::string >{ "AA", "aA", "Aa", "this", "THIS" } );
    std::cout << "Second Test: ";
    case_insensitive_cmp c;
    std::cout << c( "a", "A" ) << c( "a","b" ) << c( "A", "b" ) << "\n";
    std::cout << "Third Test: ";
    case_insensitive_hash h;
    std::cout << h( "xxx" ) << " " << h( "XXX" ) << "\n";
    std::cout << h( "Abc" ) << " " << h( "abC" ) << "\n";
    case_insensitive_equality e;
    std::cout << e( "xxx", "XXX" ) << "\n";
    // Prints ’1’.
    std::map<std::string, unsigned int, case_insensitive_cmp> freq_table = frequency_table(book);
    std::cout << freq_table["magnus"];
    std::cout << freq_table["hominum"];
    std::cout << freq_table["memoria"];
    std::pair<std::string, unsigned int> m=max_freq(freq_table);
    std::cout << m.first << " "<<m.second<<"\n";
    return 0;
}
