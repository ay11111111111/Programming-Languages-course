
#ifndef VECTORTEST_INCLUDED
#define VECTORTEST_INCLUDED  1

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>


namespace vectortest
{

   std::vector<std::string> readfile( std::istream& input );

   std::vector<std::string> randomstrings( size_t nr, size_t s );
      // Return nr random strings of length s.

   void sort_assign( std::vector< std::string > & v );
      // Sort the vector with bubble sort, using assignment for the exchanges.

   void sort_move( std::vector< std::string > & v );
      // Sort the vector with bubble sort, using std::swap for the exchanges.

   void sort_std( std::vector< std::string > & v );
      // Sort using std::sort.

}


unsigned char to_lowercase(unsigned char ch);

struct case_insensitive_cmp
{
  bool operator () ( const std::string& s1, const std::string& s2 ) const;
};

struct case_insensitive_hash
{
  size_t operator () (const std::string& s) const;
};

struct case_insensitive_equality
{
  bool operator () ( const std::string& s1, const std::string& s2 ) const;
};

std::ostream&
operator << ( std::ostream& , const std::vector< std::string > & );

std::map<std::string, unsigned int, case_insensitive_cmp>
frequency_table(const std::vector<std::string>& text);

std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality>
hashed_frequencytable( const std::vector< std::string > & text );

std::ostream&
operator << (std::ostream& stream, const std::map<std::string, unsigned int, case_insensitive_cmp>& freq);

//std::pair<std::string, unsigned int>
//max_freq(const std::map<std::string, unsigned int, case_insensitive_cmp>& freq);

#endif
