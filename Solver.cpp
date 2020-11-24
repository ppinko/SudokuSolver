#include "Solver.h"

Solver::Solver()
{
    std::set<int> tempSet {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<std::set<int>> tempVec (9, tempSet);
    for (size_t i = 0; i < 9; ++i){
        rows.push_back(tempVec);
        cols.push_back(tempVec);
        boxes.push_back(tempVec);
    }
}