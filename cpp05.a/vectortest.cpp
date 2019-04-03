
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
         
bool isdelimeter( char ch) {
	return ch == ' ' or ch == '\n' or ch == '.' or ch == ',';

}
#if 1
std::vector<std::string> 
vectortest::readfile( std::istream& input ) 
{
	std::vector<std::string> result;
	std::string last = "";
	int chars = input.get();
	while(input.good()) {
		if (isalpha(chars))
			last += char(chars);
		if (isdelimeter(chars)) {
			if (last.length() > 0) result.push_back(std::move(last));
			last.clear();

		}			
		chars = input.get();	
	}
	if (last.length() > 0) result.push_back(std::move(last));
	return result;

}

void vectortest::sort_assign( std::vector< std::string > & v )
{
}

void vectortest::sort_move( std::vector< std::string > & v )
{
}

void vectortest::sort_std( std::vector< std::string > & v )
{
}


std::ostream& 
operator << ( std::ostream& out, const std::vector< std::string > & vect ) 
{
	out << "{";
	size_t i = vect.size();
	for (auto s: vect) {
		out<<s;
		if(--i > 0) out << ", ";
	}
	out << "}";
	return out; 
}

#endif


