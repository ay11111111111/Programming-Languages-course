
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <sstream>
#include "string.h"

const string& greater( const string& s1, const string& s2 ) {
  if (s1 >= s2)
    return s1;
  return s2;
}

string&& greater( string&& s1, string&& s2 ) {

}

void part1() {
  std::cout << "--------------------------\n";
  string s1 = ("your name"); string s2 = "hallo";
  std::cout << "--------------------------\n\n";

  std::cout << "--------------------------\n";
  std::swap( s1, s2 );
  std::cout << "--------------------------\n\n";

  std::cout << "--------------------------\n";
  std::cout << ( s1 + ", " + s2 ) << "\n";
  std::cout << "--------------------------\n\n";

  std::cout << "--------------------------\n";
  std::cout << string( "this is a string" ) << "\n";
  std::cout << "--------------------------\n\n";

  std::cout << "--------------------------\n";
  s2 = ( s1 + "!" );
  std::cout << "--------------------------\n\n";

  std::cout << "--------------------------\n";
  s2 = ( s1 + "!"  + " some other string");
  std::cout << "--------------------------\n\n";
}

void part2() {
  std::cout << "--------------------------\n";
  string zz = "zz";
  std::cout << "before:\n";
  string max = greater( greater( "aa", string( "b" ) + string( "c" )),
  greater( zz, string( "cc" ))); std::cout << "after:\n";
  std::cout << "max = " << max << "\n";
  std::cout << "--------------------------\n\n";

}

int main( int argc, char* argv [] )
{
  part1();
  part2();
}
