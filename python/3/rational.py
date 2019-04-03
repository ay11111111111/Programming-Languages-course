from numbers import Number
from vector import *
from matrix import *

class Rational( Number ) :

	def __init__( self, num, denum = 1 ) :
		self.num = num
		self.denum = denum
		self.normalize()
	def normalize(self):
		if self.denum < 0:
			self.denum *= -1
			self.num *= -1
		if self.denum == 0:
			raise ArithmeticError( "Denum can not be zero" )
		n = gcd(self.num, self.denum)
		if n!=1 and n!=-1:
			self.num //= n
			self.denum //= n

	def __repr__(self):
		return str(self.num) + " / " + str(self.denum)
	
	def __neg__(self):
		return Rational(self.num * -1, self.denum)
	
	def __add__(self, other):
		if isinstance(other, int):
		    other = Rational(other)
		num = self.num * other.denum + other.num * self.denum
		denum = self.denum * other.denum
		return Rational(num, denum)

	def __sub__(self, other):
		if isinstance(other, int):
		    other = Rational(other)
		num = self.num * other.denum - other.num * self.denum
		denum = self.denum * other.denum
		return Rational(num, denum)
			

	def __radd_(self, other):
		return self + other

	def __rsub_(self, other):
		return -(self - other)
	
	def __mul__(self, other):
		if isinstance(other, int):
		    other = Rational(other)
		num = self.num * other.num
		denum = self.denum * other.denum
		return Rational(num, denum)

	def __truediv__(self, other):
		if isinstance(other, int):
		    other = Rational(other)
		num = self.num * other.denum
		denum = self.denum * other.num
		return Rational(num, denum)

	def __rmul__(self, other):
		return self * other

	def __rtruediv__(self, other):
		tmp = self / other
		return Rational(tmp.denum, tmp.num)
		
	
		
		
		

def gcd(n1, n2):
	if n1==0 and n2==0:
		raise ArithmeticError( "gcd(0,0) does not exist" )	
	while n2:
		n1, n2 = n2, n1%n2
	return n1

print(Rational(-7, 28))
