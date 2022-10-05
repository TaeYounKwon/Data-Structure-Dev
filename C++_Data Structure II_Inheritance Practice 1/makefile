CFLAGS = -std=c++14 -Wall
inheritance:    main.o square.o rectangle.o point.o
	g++ main.o square.o rectangle.o point.o -o inheritance $(CFLAGS)
	rm *.o

main.o: main.cpp square.h rectangle.h point.h
	g++ -c main.cpp $(CFLAGS)

rectangle.o:	rectangle.cpp rectangle.h point.h
	g++ -c rectangle.cpp $(CFLAGS)

square.o:	square.cpp square.h rectangle.h point.h
	g++ -c square.cpp $(CFLAGS)

point.o:	point.cpp point.h
	g++ -c point.cpp $(CFLAGS)

clean:
	rm -f *.o inheritance