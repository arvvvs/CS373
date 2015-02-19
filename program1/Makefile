all: verma_p1
CC = g++
CFLAGS =-std=c++11 -Wall -Wextra -g
all: verma_p1
verma_p1: Driver.o verma_p1.o
	$(CC) $(CFLAGS) verma_p1.o Driver.o -o verma_p1
Driver.o: Driver.cpp
	$(CC) $(CFLAGS) -c Driver.cpp -o Driver.o
verma_p1.o: verma_p1.cpp verma_p1.h
	$(CC) $(CFLAGS) -c verma_p1.cpp -o verma_p1.o
clean:
	rm *.o verma_p1 *~
