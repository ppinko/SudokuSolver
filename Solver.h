#ifndef SOLVER_H
#define SOLVER_H

#include "Puzzle.h"

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

class Solver
{
private:
    Puzzle puzzle;
    std::vector<std::vector<std::set<int>>> rows;
    std::vector<std::vector<std::set<int>>> cols;
    std::vector<std::vector<std::set<int>>> boxes;

    void InitSet();

    void SetElement(int i, int j, int val);

public:
	Solver(Puzzle &_puzzle);

    void FindNext();

    void SolvePuzzle();

    void DiscoveredElement(int i, int j, int value);

};

#endif