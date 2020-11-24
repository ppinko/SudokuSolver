#include "Solver.h"

Solver::Solver(Puzzle &_puzzle)
{   
    puzzle = _puzzle;
    std::set<int> tempSet {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<std::set<int>> tempVec (9, tempSet);
    for (size_t i = 0; i < 9; ++i){
        rows.push_back(tempVec);
        cols.push_back(tempVec);
        boxes.push_back(tempVec);
    }

    InitSet();
}

void Solver::InitSet(){
    int const width = 9;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (puzzle.puzzle[i][j] != 0)
            {
                auto temp = puzzle.puzzle[i][j];
                DiscoveredElement(i, j, temp);
            }
        }
    }
}

void Solver::DiscoveredElement(int i, int j, int value){
    // Simple removing
    rows.at(i).at(value-1).clear();
    cols.at(j).at(value-1).clear();
    int primaryBox = (i / 3) * 3 + (j / 3);
    boxes.at(primaryBox).at(value-1).clear();

    // Additional boxes
    int rowNum = (primaryBox / 3) * 3;
    int colNum = primaryBox % 3;
    int rowBox = i % 3;
    int colBox = j % 3;

    // Deal with boxes on the same row as affected one
    for (int k = 0; k < 3; ++k){
        if (rowNum + k != primaryBox){
            for (int l = 0; l < 3; ++l){
                boxes.at(rowNum+k).at(value-1).erase(rowBox*3 + l);
            }
        }
    }

    // Deal with boxes on the same column as affected one
    for (int k = 0; k < 3; ++k){
        if (colNum + 3*k != primaryBox){
            for (int l = 0; l < 3; ++l){
                boxes.at(colNum+3*k).at(value-1).erase(colBox+ 3*l);
            }
        }
    }
}

void Solver::FindNext(){
    
}

void Solver::SolvePuzzle(){
    while (!puzzle.IsSolved()){
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                if (rows[i][j].size() == 1){
                    auto it = rows[i][j].begin();
                    auto val = *it;
                    
                    SetElement(i, val, j);
                    DiscoveredElement(i, val, j);
                }
                
                if (cols[i][j].size() == 1){
                    auto it = cols[i][j].begin();
                    auto val = *it;
                    
                    SetElement(val, i, j);
                    DiscoveredElement(val, i, j);
                }

                if (boxes[i][j].size() == 1){
                    auto it = boxes[i][j].begin();
                    auto val = *it;
                    
                    // onset of the box
                    int x0 = (i / 3) * 3;
                    int y0 = (i % 3) * 3;

                    // actual point
                    x0 += val / 3;
                    y0 += val % 3;

                    SetElement(x0, y0, j);
                    DiscoveredElement(x0, y0, j);
                }
            }
        }
    }
    puzzle.PrintSolution();
}

void Solver::SetElement(int i, int j, int val){
    puzzle.puzzle[i][j] = val;
}