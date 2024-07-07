#include <iostream>
#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

// bool backTrack(vector<vector<char>> &board, vector<unordered_set<int>> row, vector<unordered_set<int>> col, vector<unordered_set<int>> grid, int r, int c)
// {
//     if (r == 9)
//         return true;

//     int next_c = (c + 1) % 9;
//     int next_r = next_c == 0 ? r + 1 : r;

//     if (board[r][c] != '.')
//         return backTrack(board, row, col, grid, next_r, next_c);

//     for (int val = 1; val < 10; val++)
//     {
//         if (row[r].find(val) == row[r].end() && col[c].find(val) == col[c].end() && grid[(r / 3) * 3 + (c / 3)].find(val) == grid[(r / 3) * 3 + (c / 3)].end())
//         {
//             board[r][c] = val + '0';
//             row[r].insert(val);
//             col[c].insert(val);
//             grid[(r / 3) * 3 + (c / 3)].insert(val);

//             if (backTrack(board, row, col, grid, next_r, next_c))
//                 return true;

//             board[r][c] = '.';
//             row[r].erase(val);
//             col[c].erase(val);
//             grid[(r / 3) * 3 + (c / 3)].erase(val);
//         }
//     }

//     return false;
// }

// void solveSudoku(vector<vector<char>> &board)
// {
//     vector<unordered_set<int>> row(9, unordered_set<int>());
//     vector<unordered_set<int>> col(9, unordered_set<int>());
//     vector<unordered_set<int>> grid(9, unordered_set<int>());

//     for (int r = 0; r < board.size(); r++)
//     {
//         for (int c = 0; c < board[0].size(); c++)
//         {
//             if (board[r][c] != '.')
//             {
//                 int val = board[r][c] - '0';
//                 row[r].insert(val);
//                 col[c].insert(val);
//                 grid[(r / 3) * 3 + (c / 3)].insert(val);
//             }
//         }
//     }

//     backTrack(board, row, col, grid, 0, 0);
//     return;
// }

bool backTrack(vector<vector<char>> &board, vector<vector<int>> row, vector<vector<int>> col, vector<vector<int>> grid, int r, int c)
{
    if (r == 9)
        return true;

    int next_c = (c + 1) % 9;
    int next_r = next_c == 0 ? r + 1 : r;

    if (board[r][c] != '.')
        return backTrack(board, row, col, grid, next_r, next_c);

    for (int val = 1; val < 10; val++)
    {
        if (!row[r][val] && !col[c][val] && !grid[(r / 3) * 3 + (c / 3)][val])
        {
            board[r][c] = val + '0';
            row[r][val] = 1;
            col[c][val] = 1;
            grid[(r / 3) * 3 + (c / 3)][val] = 1;

            if (backTrack(board, row, col, grid, next_r, next_c))
                return true;

            board[r][c] = '.';
            row[r][val] = 0;
            col[c][val] = 0;
            grid[(r / 3) * 3 + (c / 3)][val] = 0;
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    vector<vector<int>> row(9, vector<int>(10, 0));
    vector<vector<int>> col(9, vector<int>(10, 0));
    vector<vector<int>> grid(9, vector<int>(10, 0));

    for (int r = 0; r < board.size(); r++)
    {
        for (int c = 0; c < board[0].size(); c++)
        {
            if (board[r][c] != '.')
            {
                int val = board[r][c] - '0';
                row[r][val] = 1;
                col[c][val] = 1;
                grid[(r / 3) * 3 + (c / 3)][val] = 1;
            }
        }
    }

    backTrack(board, row, col, grid, 0, 0);
    return;
}

int main(int argc, char *argv[])
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            std::cout << board[i][j] << " ";
        }

        std::cout << std::endl;
    }
}