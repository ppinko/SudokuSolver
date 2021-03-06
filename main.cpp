#include "Sudoku.h"

#include <iomanip>


int main(int argc, char *argv[])
{
    std::cout << std::boolalpha;

    //TEST 1 #########################################################################

    std::cout << "\nSudoku 1 \n" << std::endl;

    std::vector<std::vector<int>> puzzle{
        {0, 0, 1, 0, 0, 0, 0, 0, 2},
        {5, 0, 3, 9, 0, 0, 7, 1, 0},
        {0, 0, 8, 1, 0, 4, 0, 0, 0},
        {3, 0, 0, 0, 8, 5, 0, 0, 7},
        {6, 0, 5, 0, 3, 0, 2, 0, 1},
        {7, 0, 0, 6, 4, 0, 0, 0, 8},
        {0, 0, 0, 5, 0, 7, 3, 0, 0},
        {0, 5, 2, 0, 0, 3, 1, 0, 9},
        {1, 0, 0, 0, 0, 0, 8, 0, 0}
    };

    auto t1 = Sudoku(puzzle);

    std::cout << t1 << std::endl;

    Sudoku::SolveAll(t1);

    //TEST 2 #########################################################################

    std::cout << "\nSudoku 2 \n" << std::endl;

    std::vector<std::vector<int>> puzzle2{
    {9, 0, 0, 1, 0, 7, 0, 5, 8},
    {8, 0, 4, 3, 0, 0, 0, 2, 0},
    {0, 0, 0, 0, 0, 2, 6, 1, 0},
    {1, 0, 0, 0, 0, 0, 5, 4, 0},
    {6, 0, 0, 0, 9, 0, 0, 0, 7},
    {0, 7, 2, 0, 0, 0, 0, 0, 6},
    {0, 4, 5, 6, 0, 0, 0, 0, 0},
    {0, 6, 0, 0, 0, 9, 2, 0, 1},
    {7, 9, 0, 8, 0, 3, 0, 0, 5}
    };

    auto t2 = Sudoku(puzzle2);

    std::cout << t2 << std::endl;

    Sudoku::SolveAll(t2);

    //TEST 3 (medium) 10th puzzle #########################################################################

    std::cout << "\nSudoku 3 \n" << std::endl;

    std::vector<std::vector<int>> puzzle3{
    {4, 5, 0, 0, 0, 0, 2, 3, 0},
    {3, 0, 0, 7, 0, 2, 0, 0, 0},
    {2, 9, 0, 0, 0, 0, 6, 0, 0},
    {5, 0, 0, 4, 0, 0, 1, 0, 0},
    {0, 0, 0, 8, 6, 1, 0, 0, 0},
    {0, 0, 2, 0, 0, 3, 0, 0, 4},
    {0, 0, 6, 0, 0, 0, 0, 9, 3},
    {0, 0, 0, 9, 0, 6, 0, 0, 8},
    {0, 4, 9, 0, 0, 0, 0, 6, 1}
    };

    auto t3 = Sudoku(puzzle3);

    std::cout << t3 << std::endl;

    Sudoku::SolveAll(t3);

    //TEST 4 (hard) 84th puzzle #########################################################################

    std::cout << "\nSudoku 4 \n" << std::endl;

    std::vector<std::vector<int>> puzzle4{
    {0, 0, 0, 0, 1, 0, 0, 0, 9},
    {0, 0, 3, 0, 0, 0, 0, 7, 5},
    {0, 2, 8, 0, 0, 3, 0, 0, 0},
    {2, 0, 0, 0, 0, 7, 0, 8, 0},
    {0, 0, 7, 0, 8, 0, 9, 0, 0},
    {0, 4, 0, 9, 0, 0, 0, 0, 1},
    {0, 0, 0, 6, 0, 0, 1, 2, 0},
    {5, 7, 0, 0, 0, 0, 6, 0, 0},
    {1, 0, 0, 0, 9, 0, 0, 0, 0}
    };

    auto t4 = Sudoku(puzzle4);

    std::cout << t4 << std::endl;

    Sudoku::SolveAll(t4);

    return 0;
}
