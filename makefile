CC=g++
CFLAGS=-c -Wall -std=c++0x

all: nanoSemiconductor

nanoSemiconductor: nanoSemiconductor.o main.o 
	$(CC) main.o nanoSemiconductor.o -o nanoSemiconductor

nanoSemiconductor.o: nanoSemiconductor.cxx
	$(CC) $(CFLAGS) nanoSemiconductor.cxx

main.o: main.C
	$(CC) $(CFLAGS) main.C



clean:
	rm -rf *o nanoSemiconductor
