from matrix import *
from vector import *
from rational import *

from matrix import *
from vector import *
from rational import *

def tests():
	print("#1")
	m1 = Matrix(Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8))
	m2 = Matrix(Rational(-1, 3), Rational(2, 7),
	       Rational(2, 5), Rational(-1, 7))

	m3 = m1 @ m2
	print(m3, end="")
	print()

	print("#2")
	m1 = Matrix(Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8))

	m1_inv = m1.inverse()
	print(m1_inv, end="")
	print()

	print("#3a")
	m1 = Matrix(Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8))
	m2 = Matrix(Rational(-1, 3), Rational(2, 7),
	       Rational(2, 5), Rational(-1, 7))
	m3 = Matrix(Rational(1, 4), Rational(2, 3), Rational(1, 4), Rational(-1, 3))

	print("(m1 @ m2) @ m3 == m1 @ (m2 @ m3)")
	LHS = (m1 @ m2) @ m3
	RHS = m1 @ (m2 @ m3)
	print(RHS - LHS, end="")
	print()

	print("#3b")
	m1 = Matrix(Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8))
	m2 = Matrix(Rational(-1, 3), Rational(2, 7),
	       Rational(2, 5), Rational(-1, 7))
	m3 = Matrix(Rational(1, 4), Rational(2, 3), Rational(1, 4), Rational(-1, 3))

	print("m1 @ (m2 + m3) == m1 @ m2 + m1 @ m3")
	LHS = m1 @ (m2 + m3)
	RHS = m1 @ m2 + m1 @ m3
	print(RHS - LHS)

	print("(m1 + m2) @ m3 == m1 @ m3 + m2 @ m3")
	LHS = (m1 + m2) @ m3
	RHS = m1 @ m3 + m2 @ m3
	print(RHS - LHS, end="")
	print()

	print("#3c")
	m1 = Matrix(Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8))
	m2 = Matrix(2, -3, 5, -10)
	v = Vector(2, 3)

	print("m1 @ (m2 @ m3) == (m1 @ m2) @ m3")
	LHS = m1 @ (m2 @ m3)
	RHS = (m1 @ m2) @ m3
	print(RHS - LHS, end="")
	print()

	print("#3d")
	m1 = Matrix(Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8))
	m2 = Matrix(2, -3, 5, -10)

	print("det(m1) * det(m2) == det(m1 @ m2)")
	LHS = m1.determinant() * m2.determinant()
	RHS = (m1 @ m2).determinant()
	print(RHS - LHS)
	print()

	print("#3e")
	A = Matrix(Rational(2), Rational(-3), Rational(5), Rational(-10))
	A_inv = A.inverse()
	I = Matrix(Rational(1), Rational(0), Rational(0), Rational(1))

	print("A @ inv(A) == I")
	LHS = A @ A_inv
	RHS = I
	print(RHS - LHS)
	print()

	print("inv(A) @ A == I")
	LHS = A_inv @ A
	RHS = I
	print(RHS - LHS)
	print()


if __name__ == "__main__":
	tests()

