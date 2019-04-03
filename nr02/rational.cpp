
#include "rational.h"

// Complete these methods:

int rational::gcd( int n1, int n2 ) {
  while (n2) {
    n1 %= n2;
    std::swap(n1, n2);
  }
  return n1;
}

void rational::normalize( ) {
  int g = rational::gcd(num, denum);

  num /= g;
  denum /= g;
  if (denum < 0) {
    denum *= -1;
    num *= -1;
  }
}

rational operator - ( rational r ) {
  rational tmp(-r.num, r.denum);
  return tmp;
}

rational operator + ( const rational& r1, const rational& r2 ) {
  int n_num = r1.num * r2.denum + r1.denum * r2.num;
  int n_denum = r1.denum * r2.denum;
  rational tmp(n_num, n_denum);
  return tmp;
}

rational operator - ( const rational& r1, const rational& r2 ) {
  return r1 + (-r2);
}

rational operator * ( const rational& r1, const rational& r2 ) {
  int n_num = r1.num * r2.num;
  int n_denum = r1.denum * r2.denum;
  rational tmp(n_num, n_denum);
  return tmp;
}

rational operator / ( const rational& r1, const rational& r2 ) {
    int n_num = r1.num * r2.denum;
    int n_denum = r1.denum * r2.num;
    rational tmp(n_num, n_denum);
    return tmp;
}

bool operator == ( const rational& r1, const rational& r2 );
bool operator != ( const rational& r1, const rational& r2 );

std::ostream& operator << ( std::ostream& out, const rational& r ) {
  if (r.denum == 1)
    out << r.num;
  else
    out << r.num << "/" << r.denum;
  return out;
}
