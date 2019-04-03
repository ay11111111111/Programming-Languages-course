#include "unordered_maptest.h"

#include <vector>
#include <cctype>

bool case_insensitive_equality::operator()(const std::string& s1,
                                           const std::string& s2) const {
  if (s1.length() != s2.length()) return false;

  for (size_t i = 0; i < s1.length(); i++) {
    char c1 = std::tolower(s1[i]);
    char c2 = std::tolower(s2[i]);

    if (c1 != c2) {
      return false;
    }
  }
  return true;
}

// Ripped from:
// https://stackoverflow.com/a/8317670/7684824
size_t case_insensitive_hash::operator()(const std::string& s) const {
  unsigned int b    = 378551;
  unsigned int a    = 63689;
  unsigned int hash = 0;

  for (std::size_t i = 0; i < s.length(); i++)
  {
    hash = hash * a + std::tolower(s[i]);
    a    = a * b;
  }

  // return hash & 0x7FFFFFFF;
  return hash;
}

umap_t unordered_maptest::frequencytable(const std::vector<std::string>& text) {
  umap_t cnt;

  for (auto s: text) cnt[s]++;
  return cnt;
}

umap_t::const_iterator unordered_maptest::most_frequent(const umap_t& table) {
  auto result = table.end();

  for (auto it = table.begin(); it != table.end(); it++) {
    if ((result == table.end()) || (result->second < it->second)) result = it;
  }
  return result;
}

std::ostream& operator<<(std::ostream& stream, const umap_t& freq) {
  for (auto p: freq) stream << p.first << " " << p.second << "\n";
  return stream;
}
