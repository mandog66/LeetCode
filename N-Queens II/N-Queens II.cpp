#include <iostream>
#include <vector>

using std::vector;

vector<vector<int>> remove_queen(int row, int col, int n, vector<vector<int>> attachZone)
{
    for (int i = 0; i < n; i++)
    {
        attachZone[row][i] = 0;
        attachZone[i][col] = 0;
    }

    int i = row, j = col;
    while (i >= 0 && j >= 0 && i < n && j < n)
        attachZone[i--][j++] = 0;

    i = row, j = col;
    while (i >= 0 && j >= 0 && i < n && j < n)
        attachZone[i++][j--] = 0;

    i = row, j = col;
    while (i >= 0 && j >= 0 && i < n && j < n)
        attachZone[i++][j++] = 0;

    i = row, j = col;
    while (i >= 0 && j >= 0 && i < n && j < n)
        attachZone[i--][j--] = 0;

    return attachZone;
}

vector<vector<int>> place_queen(int row, int col, int n, vector<vector<int>> attachZone)
{
    for (int i = 0; i < n; i++)
    {
        attachZone[row][i] = 1;
        attachZone[i][col] = 1;
    }

    int i = row, j = col;
    while (i >= 0 && j >= 0 && i < n && j < n)
        attachZone[i--][j++] = 1;

    i = row, j = col;
    while (i >= 0 && j >= 0 && i < n && j < n)
        attachZone[i++][j--] = 1;

    i = row, j = col;
    while (i >= 0 && j >= 0 && i < n && j < n)
        attachZone[i++][j++] = 1;

    i = row, j = col;
    while (i >= 0 && j >= 0 && i < n && j < n)
        attachZone[i--][j--] = 1;

    return attachZone;
}

int helper(int row, int col, int n, vector<vector<int>> attackZone, int &res, int chess)
{
    vector<vector<int>> temp = attackZone;
    for (int i = row + 1; i < n; i++)
    {
        int o_chess = chess;
        for (int j = 0; j < n; j++)
        {
            if (temp[i][j] == 1)
                continue;
            else
            {
                attackZone = place_queen(i, j, n, temp);
                chess = helper(i, j, n, attackZone, res, chess + 1);
            }
        }

        if (o_chess == chess)
            return chess - 1;
    }

    if (chess == n)
        res += 1;

    return chess - 1;
}

int totalNQueens(int n)
{
    if (n == 1)
        return 1;

    int res = 0;
    for (int row = 0; row < n / 2; row++)
    {
        for (int col = 0; col < n; col++)
        {
            vector<vector<int>> attackZone(n, vector<int>(n, 0));
            attackZone = place_queen(row, col, n, attackZone);
            int chess = helper(row, col, n, attackZone, res, 1);
        }
    }

    return res;
}

int main(int argc, char *argv[])
{
    int n = 1;
    std::cout << totalNQueens(n) << std::endl; // 1

    n = 2;
    std::cout << totalNQueens(n) << std::endl; // 0

    n = 3;
    std::cout << totalNQueens(n) << std::endl; // 0

    n = 4;
    std::cout << totalNQueens(n) << std::endl; // 2

    n = 5;
    std::cout << totalNQueens(n) << std::endl; // 10

    n = 6;
    std::cout << totalNQueens(n) << std::endl; // 4

    n = 7;
    std::cout << totalNQueens(n) << std::endl; // 40

    n = 8;
    std::cout << totalNQueens(n) << std::endl; // 92

    n = 9;
    std::cout << totalNQueens(n) << std::endl; // 352
}