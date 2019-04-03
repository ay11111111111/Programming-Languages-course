
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wall -std=c++14 -O3 -flto
CPP = g++


nr06 : Makefile   nr06.o listtest.o vectortest.o
	$(CPP) $(Flags) -o nr06   nr06.o listtest.o vectortest.o

nr06.o : Makefile   nr06.cpp   vectortest.h listtest.h timer.h
	$(CPP) -c $(Flags) nr06.cpp -o  nr06.o

listtest.o : Makefile   listtest.cpp   listtest.h
	$(CPP) -c $(Flags) listtest.cpp -o  listtest.o

vectortest.o : Makefile   vectortest.cpp   vectortest.h
	$(CPP) -c $(Flags) vectortest.cpp -o  vectortest.o

maptest.o : Makefile   maptest.cpp   maptest.h
	$(CPP) -c $(Flags) maptest.cpp -o  maptest.o

unordered_maptest.o : Makefile   unordered_maptest.cpp   unordered_maptest.h
	$(CPP) -c $(Flags) unordered_maptest.cpp -o  unordered_maptest.o


main : Makefile   main.o vectortest.o unordered_maptest.o maptest.o
	$(CPP) $(Flags) -o main		main.o	vectortest.o unordered_maptest.o maptest.o

main.o : Makefile   main.cpp vectortest.h unordered_maptest.h maptest.h
	$(CPP) -c $(Flags) main.cpp -o main.o

book : Makefile   book.o vectortest.o unordered_maptest.o maptest.o
	$(CPP) $(Flags) -o book		book.o	vectortest.o unordered_maptest.o maptest.o

book.o : Makefile   book.cpp vectortest.h unordered_maptest.h maptest.h
	$(CPP) -c $(Flags) book.cpp -o book.o

clean:
	rm -rf nr06 main book *.o
