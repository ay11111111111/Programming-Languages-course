
#include "string.h"
#include <iostream>

std::ostream& operator << ( std::ostream& out, const string& s )
{
  for (char c : s)
    out << c;
  return out;   // Always return the stream!
}

char string::operator [] ( size_t i ) const {
  return this -> p[i];
}
char& string::operator [] ( size_t i ) {
  char & tmp = this -> p[i];
  return tmp;
}
size_t string::size( ) const {
  return this->len;
}
string& string::operator += ( char c ) {
  char * buff = new char[len + 1];
  for (int i = 0; i < len; i++)
    buff[i] = p[i];
  buff[len++] = c;
  p = buff;
  return *this;
}

string& operator += ( string& s1, const string& s2 ) {
  char * buff = new char[s1.len + s2.len + 1];
  int j = 0;
  for (int i = 0; i < s1.len; i++, j++)
    buff[j] = s1[i];
  for (int i = 0; i < s2.len; i++, j++)
    buff[j] = s2[i];
  buff[j++] = 0;
  // std::cout << "|" << s1 << "|" << s2 << "|" << buff << "|\n";
  s1 = string(buff);
  return s1;
}

string operator + ( string s1, const string& s2 ) {
  // s1 += s2;
  return s1 += s2;
}

bool operator == ( const string& s1, const string& s2 ) {
  if (s1.len != s2.len)
    return false;
  for (int i = 0; i < s1.len; i++)
    if (s1[i] != s2[i])
      return false;
  return true;
}
bool operator < ( const string& s1, const string& s2 ) {
    if (s1.len != s2.len)
      return s1.len < s2.len;
    for (int i = 0; i < s1.len; i++)
      if (s1[i] != s2[i])
        return s1[i] < s2[i];
    return false;
}
