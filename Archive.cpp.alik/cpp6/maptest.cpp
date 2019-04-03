#include "maptest.h"

#include <vector>
#include <cctype>

bool case_insensitive_cmp::operator()(const std::string& s1,
                                      const std::string& s2) const {

  for (size_t i = 0; i < min(s1.length(), s2.length()); i++) {
    if (std::tolower(s1[i]) != std::tolower(s2[i])) {
      return std::tolower(s1[i]) < std::tolower(s2[i]);
    }
  }
  return s1.length() < s2.length();
}

map_t maptest::frequencytable(const std::vector<std::string>& text) {
  map_t cnt;

  for (auto s: text) cnt[s]++;
  return cnt;
}

map_t::const_iterator
maptest::most_frequent(const map_t& table) {
  auto result = table.end();

  for (auto it = table.begin(); it != table.end(); it++) {
    if ((result == table.end()) || (result->second < it->second)) result = it;
  }
  return result;
}

std::ostream& operator<<(std::ostream& stream, const map_t& freq) {
  for (auto p: freq) stream << p.first << " " << p.second << "\n";
  return stream;
}
