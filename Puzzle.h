#ifndef PUZZLE_H
#define PUZZLE_H

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

class Puzzle
{
public:
    std::vector<std::vector<int>> initialPuzzle;
    std::vector<std::vector<int>> puzzle;
    std::vector<std::vector<int>> solution;

    void PrintState(std::vector<std::vector<int>> const &state);

public:
	Puzzle(std::vector<std::vector<int>> _puzzle);
    
    void PrintInitialPuzzle();

    void PrintCurrentState();

    void PrintSolution();

    bool IsSolved() const;
};

#endif