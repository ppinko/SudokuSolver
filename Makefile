#declare variables
CC=g++

CFLAGS=-c -Wall

all: file

file: main.o Sudoku.o
	$(CC) main.o Sudoku.o -o executable

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Sudoku.o: Sudoku.cpp
	$(CC) $(CFLAGS) Sudoku.cpp

clean:
	rm -rf *o executable
