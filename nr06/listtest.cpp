
#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>

void listtest::sort_move(std::list<std::string>& v)
{
  for (auto j = v.begin(); j != v.end(); ++j)
    for (auto i = v.begin(); i != j; ++i)
    {
      if (*i > *j) {
        std::swap(*i, *j);
      }
    }
}

void listtest::sort_assign(std::list<std::string>& v)
{
  for (auto j = v.begin(); j != v.end(); ++j)
    for (auto i = v.begin(); i != j; ++i)
    {
      if (*i > *j) {
        std::string s = *i; *i = *j;
        *j = s;
      }
    }
}

std::ostream&
operator << (std::ostream& out, const std::list<std::string>& list)
{
  out << "{";
  size_t i = list.size();

  for (auto s: list) 
  {
    out << s;
    if (--i > 0) 
        out << ", ";
  }

  out << "}";
  return out;
}

std::list<std::string>listtest::from_vector(const std::vector<std::string>& v) 
{
  std::list<std::string> result;

  for (auto s: v) 
    result.push_back(s);

  return result;
}

