#declare variables
CC=g++

CFLAGS=-c -Wall

all: file

file: main.o Sudoku.o Puzzle.o Solver.o
	$(CC) main.o Sudoku.o Puzzle.o Solver.o -o executable

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Sudoku.o: Sudoku.cpp
	$(CC) $(CFLAGS) Sudoku.cpp

Solver.o: Solver.cpp
	$(CC) $(CFLAGS) Solver.cpp

Puzzle.o: Puzzle.cpp
	$(CC) $(CFLAGS) Puzzle.cpp

clean:
	rm -rf *o executable