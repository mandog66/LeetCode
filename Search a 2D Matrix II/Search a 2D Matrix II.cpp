#include <iostream>
#include <vector>

using std::vector;

bool helper(vector<vector<int>> &matrix, int target, int row, int col, int n, int m)
{
    if (row < 0 || col < 0 || row >= n || col >= m)
        return false;

    if (matrix[row][col] == target)
        return true;
    else if (matrix[row][col] < target)
    {
        if (col + 1 < m)
            return helper(matrix, target, row, col + 1, n, m);
        else
            return helper(matrix, target, row + 1, col, n, m);
    }

    else
    {
        if (col - 1 >= 0)
            return helper(matrix, target, row, col - 1, n, col);
        else
            return helper(matrix, target, row - 1, col, row, m);
    }
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    return helper(matrix, target, 0, 0, n, m);
}

int main(int argc, char *argv[])
{
    // vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    // std::cout << (searchMatrix(matrix, 5) ? "True" : "False") << std::endl;  // True
    // std::cout << (searchMatrix(matrix, 20) ? "True" : "False") << std::endl; // False
    // std::cout << (searchMatrix(matrix, 19) ? "True" : "False") << std::endl; // True

    vector<vector<int>> matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    std::cout << (searchMatrix(matrix, 19) ? "True" : "False") << std::endl; // True
}