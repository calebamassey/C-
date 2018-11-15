a.out: mytest.o sorted.o
	g++ -Wall mytest.o sorted.o

mytest.o: mytest.cpp sorted.h
	g++ -c -Wall mytest.cpp

sorted.o: sorted.cpp sorted.h
	g++ -c -Wall sorted.cpp