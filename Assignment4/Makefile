all: a4.o LL2.o
	g++ -Wall -o a4 a4.o LL2.o

a4.o: a4.cpp LL2.h
	g++ -Wall -o a4.o -c a4.cpp 

LL2.o: LL2.cpp LL2.h
	g++ -Wall -o LL2.o -c LL2.cpp
	
clean:
	rm -f a4 *.o