
#include "rational.h"
#include "matrix.h"

int main( int argc, char* argv [ ] )
{
  rational r1( 2, 6 );
  rational r2( 4, 3 );
  rational r3( 5, 6 );
  rational r4( 1, 2 );

  std::cout << r1 << " " << r2 << "\n";
  std::cout << r3 << " " << r4 << "\n";
  std::cout << r1 + r2 << "\n";
  std::cout << r1 - r2 << "\n";
  std::cout << r1 * r2 << "\n";
  std::cout << r1 / r2 << "\n";

  matrix m1 = { { {1,2}, {-2,7} }, { {1,3}, {2,8} } };
  std::cout << m1 << "\n";

  matrix m2 = { { {-1,3}, {2,5} }, { { 2,7 }, { -1,7 } } };
  std::cout << m2 << "\n";

  std::cout << m1 * m2 << "\n";
  std::cout << m1.inverse( ) << "\n";

  matrix m3 = { { 4,5}, { -1, 2 }};

  std::cout << m1.determinant( ) << "\n";

  std::cout << m1.adjugate( ) << "\n";
  std::cout << m1.inverse( ) * m1 << "\n";

  std::cout << "Associativity:\n";
  std::cout << ((m1 * m2) * m3) - (m1 * (m2 * m3)) << "\n";

  std::cout << "Distributivity:\n";
  std::cout << (m1 * (m2 + m3)) - (m1 * m2 + m1 * m3) << "\n";
  std::cout << ((m1 + m2) * m3) - (m1 * m3 + m2 * m3) << "\n";

  vector v = {{1, 2}, {3, 4}};
  std::cout << v << "\n";

  std::cout << "Matrix multiplication corresponds to composition of application:\n";
  std::cout << (m1(m2(v))) << " " << ((m1 * m2)(v)) << "\n";

  std::cout << "Determinant commutes over multiplication:\n";
  std::cout << (m1.determinant( ) * m2.determinant( )) - ((m1 * m2).determinant()) << "\n";

  std::cout << "Inverse of matrix is indeed inverse:\n";
  std::cout << (m1.inverse( ) * m1) << "\n";
  std::cout << (m1 * m1.inverse( )) << "\n";

}
