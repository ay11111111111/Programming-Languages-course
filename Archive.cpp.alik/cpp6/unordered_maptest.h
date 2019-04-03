
#ifndef UNORDERED_MAPTEST_INCLUDED
#define UNORDERED_MAPTEST_INCLUDED   1

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>

// I agree that the use of namespace in this little exercise
// is a bit exaggerated, but one has to learn this technique.

struct case_insensitive_equality {
  bool operator()(const std::string& s1,
                  const std::string& s2) const;

  // Return true if s1 < s2, ignoring case of the letters.
};

struct case_insensitive_hash {
  size_t operator()(const std::string& s) const;
};

using umap_t = std::unordered_map<std::string, unsigned int,
                                  case_insensitive_hash,
                                  case_insensitive_equality>;

namespace unordered_maptest {
umap_t                 frequencytable(const std::vector<std::string>& text);
umap_t::const_iterator most_frequent(const umap_t&);
}

std::ostream&
operator<<(std::ostream&,
           const umap_t&);

// Must be not in namespace.

#endif // ifndef UNORDERED_MAPTEST_INCLUDED
