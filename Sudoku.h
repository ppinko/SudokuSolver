#ifndef SUDOKU_H
#define SUDOKU_H

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

class Sudoku
{
public:
	Sudoku(std::vector<std::vector<int>> toSolved);

	friend std::ostream &operator<<(std::ostream& os, const Sudoku& sud);

	bool Solve(std::queue<Sudoku> &possibilities, int &subCounter);

	bool IsFinal() const;

	static void SolveAll(Sudoku initValue);

	std::vector<std::vector<int>> solution;

	//Missing values in row
	std::vector<std::set<int>> rows;

	//Missing values in columns
	std::vector<std::set<int>> cols;

	//Missing values in box
	std::vector<std::set<int>> boxes;

	void InitSetUp();

	
};

#endif
