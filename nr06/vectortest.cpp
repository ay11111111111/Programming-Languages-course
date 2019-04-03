
#include "vectortest.h"

#include <random>
#include <chrono>
#include <algorithm>

std::vector< std::string >
vectortest::randomstrings( size_t nr, size_t s )
{
   static std::default_random_engine gen(
      std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );
         // Narrowing long int into int, but that is no problem.

   static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
   static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1 );
      // More narrowing.

   std::vector< std::string > res;

   for( size_t i = 0; i < nr; ++ i )
   {
      std::string rand;
      for( size_t j = 0; j < s; ++ j )
      {
         rand. push_back( alphabet[ distr( gen ) ] );
      }

      res. push_back( std::move( rand ));
   }
   return res;
}


std::vector<std::string>
vectortest::readfile( std::istream& input )
{
   std::vector<std::string> result;
   std::string last = "";
   char ch = input.get();

   while (input.good())
   {
      if (isalpha(ch))
      {
         last += ch;
      }
      else if (!isalpha(ch) && last.length() > 0)
      {
         result.push_back(std::move(last));
         last.clear();
      }

      ch = input.get();
   }

   if (last.length() > 0)
      result.push_back(std::move(last));

   return result;
}

void vectortest::sort_assign(std::vector<std::string>& v)
{
  for (size_t j = 0; j < v.size(); ++j)
    for (size_t i = 0; i < j; ++i)
    {
      if (v[i] > v[j]) {
        std::string s = v[i]; v[i] = v[j];
        v[j] = s;
      }
    }
}

void vectortest::sort_move(std::vector<std::string>& v)
{
  for (size_t j = 0; j < v.size(); ++j)
    for (size_t i = 0; i < j; ++i)
    {
      if (v[i] > v[j]) {
        std::swap(v[i], v[j]);
      }
    }
}

void vectortest::sort_std(std::vector<std::string>& v)
{
  std::sort(v.begin(), v.end());
}


std::ostream&
operator << ( std::ostream& out, const std::vector< std::string > & vect )
{
   out << "{";
   size_t i = vect.size();

   for (auto s : vect)
   {
      out << s;
      if (--i > 0)
         out << ", ";
   }

   out << "}";
   return out;
}
//CPP06_3
bool case_insensitive_cmp::operator () ( const std::string& s1, const std::string& s2 ) const
  {
      for(auto it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end() && it2 != s2.end(); it1++, it2++)
    {
      if(tolower(*it1) > tolower(*it2))
        return false;
      else if(tolower(*it1) != tolower(*it2))
        return true;
    }

    return (s1.length() < s2.length());
  }


  size_t case_insensitive_hash::operator () (const std::string& s) const
  {
    size_t b    = 378551;
    size_t a    = 63689;
    size_t hash = 0;

    for(std::size_t i = 0; i < s.length(); i++)
    {
        hash = hash * a + tolower(s[i]);
        a    = a * b;
    }

    return hash;
  }


 bool case_insensitive_equality::operator () ( const std::string& s1, const std::string& s2 ) const
  {
    if(s1.length() != s2.length())
      return false;

    for(auto it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end() && it2 != s2.end(); it1++, it2++)
    {
      if(tolower(*it1) != tolower(*it2))
          return false;
    }

    return true;
  }

//CPP06_1
std::map<std::string, unsigned int, case_insensitive_cmp>
frequency_table(const std::vector<std::string>& text)
{
  std::map<std::string, unsigned int, case_insensitive_cmp> my_map;
  for (auto str : text)
  {
    ++my_map[str];
  }
  return my_map;
}

std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality>
hashed_frequencytable( const std::vector< std::string > & text )
{
  std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality> my_map;
  for (auto str : text)
  {
    ++my_map[str];
  }
  return my_map;
}

//CPP06_2
std::ostream&
operator << (std::ostream& stream, const std::map<std::string, unsigned int, case_insensitive_cmp>& freq)
{
  stream << "-----------------" << "\n";
  for (auto const& pair : freq)
  {
    stream << pair.first << ":" << pair.second << "\n";
  }
  stream << "-----------------" << "\n";
  return stream;
}
