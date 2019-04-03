
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <sstream>
#include "string.h"


int main( int argc, char* argv [ ] )
{
  string s1 = "good";
  string s2 = "evening";
  std::cout << s1 << s2 << "\n";
  std::cout << s1[1] << " " << s1.size() << "\n";
  s1 += '_';
  std::cout << s1 << "\n";
  s1 += s2;
  std::cout << s1 << "\n";
  s1 += s1;
  std::cout << s1 << "\n";

  s1 = s1 + s1;
  std::cout << s1 << "\n";


  s1 = "good";
  s2 = "evening";
  string s3 = "good_evening";
  string s4 = s1 + "_" + s2;
  string s5 = s2;
  s5 = s1;
  std::cout << "s5" << s5 << "\n";

  std::cout << s4 << " " << s3 << "\n";
  if (s4 ==  s3) {
    std::cout << "equal\n";
  } else {
    if (s4 < s3)
      std::cout << "less\n";
    else
      std::cout << "more\n";
  }
}
