#include "Puzzle.h"

Puzzle::Puzzle(std::vector<std::vector<int>> _puzzle)  
{
    puzzle = _puzzle;
    initialPuzzle = _puzzle;
    solution = _puzzle;
};

void Puzzle::PrintState(std::vector<std::vector<int>> const &state){
    auto const width = 9U;
    for (size_t i = 0; i < width; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (state[i][j] == 0)
                std::cout << "-" << " ";
            else
                std::cout << state[i][j] << " ";
        }
        std::cout << std::endl;
    }
};

void Puzzle::PrintInitialPuzzle(){
    PrintState(initialPuzzle);
};

void Puzzle::PrintCurrentState(){
    PrintState(puzzle);
};

void Puzzle::PrintSolution(){
    PrintState(solution);
};