#include "Sudoku.h"

//Constructor
Sudoku::Sudoku(std::vector<std::vector<int>> toSolved)
{
    solution = toSolved;

    rows = {
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
    };

    cols = {
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
    };

    boxes = {
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
    };
}

std::ostream& operator<<(std::ostream& os, const Sudoku& sud)
{
    auto const width = 9;
    for (size_t i = 0; i < width; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (sud.solution[i][j] == 0)
                os << "-" << " ";
            else
                os << sud.solution[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

void Sudoku::InitSetUp()
{
    size_t const width = 9;
    for (size_t i = 0; i < width; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (solution[i][j] != 0)
            {
                auto temp = solution[i][j];
                rows.at(i).erase(temp);
                cols.at(j).erase(temp);
                boxes.at((i / 3) * 3 + (j / 3)).erase(temp);
            }
        }
    }
}

bool Sudoku::IsFinal() const
{
    return std::all_of(rows.cbegin(), rows.cend(), [](std::set<int> s) {return s.empty(); });
}

bool Sudoku::Solve(std::queue<Sudoku> &possibilities, int &subCounter)
{
    InitSetUp();
    auto const width = 9;
    auto counter = 1;
    while (true)
    {

        //Sygnalise no change during iterations
        auto flag = false;

        //Collect highest possibility field (lowest number of left numbers)
        //0 - num of possibilities, 1 - i, 2 - j
        std::vector<int> deviation{9, 0, 0};
        std::vector<int> deviationOptions{};

        for (auto i = 0; i < width; ++i)
        {
            for (auto j = 0; j < width; ++j)
            {
                if (solution[i][j] != 0)
                {
                    continue;
                }

                //Intersect rows, cols and boxes to check what are possibilities
                std::vector<int> temp{}, merged{};
                std::set_intersection(rows.at(i).cbegin(), rows.at(i).cend(), cols.at(j).cbegin(), cols.at(j).cend(),
                    std::back_inserter(temp));
                auto pos = (i / 3) * 3 + (j / 3);
                std::set_intersection(temp.cbegin(), temp.cend(), boxes.at(pos).cbegin(), boxes.at(pos).cend(),
                    std::back_inserter(merged));


                if (merged.size() == 0)
                {
                    ++subCounter;
                    return false;
                }

                //One element means one possibility
                if (merged.size() == 1)
                {
                    flag = true;
                    auto guessed = merged.front();
                    solution[i][j] = guessed;
                    rows.at(i).erase(guessed);
                    cols.at(j).erase(guessed);
                    boxes.at((i / 3) * 3 + (j / 3)).erase(guessed);
                }
                else if(!flag)
                {
                    if (merged.size() < deviation[0])
                    {
                        deviation = {static_cast<int>(merged.size()), i, j };
                        deviationOptions = merged;
                    }
                }
            }
        }
        if (IsFinal())
        {
            return true;
        }
        if (!flag)
        {
            for (auto k = 0; k < deviationOptions.size(); ++k)
            {
                solution[deviation[1]][deviation[2]] = deviationOptions[k];
                possibilities.push(*this);
            }
            return false;
        }
    }
}

void Sudoku::SolveAll(Sudoku initValue)
{
    std::queue<Sudoku> possibilities{};
    possibilities.push(initValue);
    int subCounter = 0;
    while(true)
    {
        auto next = possibilities.front();
        possibilities.pop();
        if (next.Solve(possibilities, subCounter))
        {
            ++subCounter;
            std::cout << std::endl << "##### Solved Sudoku #####" << std::endl
            << "##### Possibilities checked: " << subCounter << " #####" << std::endl << std::endl;
            std::cout << next << std::endl;
            return;
        }
        if (possibilities.empty())
        {
            std::cout << "Something went wrong, solution not found!!!" << std::endl;
            return;
        }
    }
}
