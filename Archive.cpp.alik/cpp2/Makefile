# The -Wall option sets all warnings on. Take warnings seriously:
# c++14 is the C++ standard (from 2014).
# It is important to use c++11 at least, because in that year
# there was a big reform.

main : main.o matrix.o rational.o
	g++ -o main main.o matrix.o rational.o

main.o : main.cpp matrix.h rational.h
	g++ -o main.o -c main.cpp -Wall -std=c++14

matrix.o : matrix.cpp matrix.h vector.h rational.h
	g++ -o matrix.o -c matrix.cpp -Wall -std=c++14

rational.o : rational.cpp rational.h
	g++ -o rational.o -c rational.cpp -Wall -std=c++14

clean:
	rm -rf main *.o
