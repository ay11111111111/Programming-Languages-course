
#ifndef MAPTEST_INCLUDED
#define MAPTEST_INCLUDED   1

#include <map>
#include <string>
#include <fstream>
#include <iostream>

// I agree that the use of namespace in this little exercise
// is a bit exaggerated, but one has to learn this technique.

struct case_insensitive_cmp {
  bool operator()(const std::string& s1,
                  const std::string& s2) const;

  // Return true if s1 < s2, ignoring case of the letters.
};

using map_t = std::map<std::string, unsigned int, case_insensitive_cmp>;
namespace maptest {
map_t                 frequencytable(const std::vector<std::string>& text);

map_t::const_iterator most_frequent(const map_t& table);
}

std::ostream&
operator<<(std::ostream&,
           const map_t&);

// Must be not in namespace.

#endif // ifndef MAPTEST_INCLUDED
