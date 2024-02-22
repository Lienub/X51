CC = g++
CPPFLAGS = -Wall -Wextra -O3 -std=c++11

all: main

io.o: io.cpp image.h image.hpp
	$(CC) $(CPPFLAGS) -c io.cpp

main: main.o io.o transformations_valeurs.o transformations_valeurs_rgb.o filtres.o
	$(CC) $(CPPFLAGS) main.o io.o transformations_valeurs.o transformations_valeurs_rgb.o filtres.o -o main

main.o: main.cpp image.h image.hpp io.h transformations_valeurs.h
	$(CC) $(CPPFLAGS) -c main.cpp 

filtres.o: filtres.cpp filtres.h
	$(CC) $(CPPFLAGS) -c filtres.cpp

transformations_valeurs.o: transformations_valeurs.cpp transformations_valeurs.h
	$(CC) $(CPPFLAGS) -c transformations_valeurs.cpp

transformations_valeurs_rgb.o: transformations_valeurs_rgb.cpp transformations_valeurs_rgb.h
		$(CC) $(CPPFLAGS) -c  transformations_valeurs_rgb.cpp

clean:
	rm *.o main