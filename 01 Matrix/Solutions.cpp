#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

std::ostream &operator<<(std::ostream &out, const vector<vector<int>> &mat)
{
    const int n = mat.size();
    const int m = mat[0].size();

    out << "[";
    for (int i = 0; i < n; i++)
    {
        out << "[";

        for (int j = 0; j < m; j++)
        {
            out << (j != 0 ? ", " : "") << mat[i][j];
        }

        out << "]" << (i == (n - 1) ? "" : "\n");
    }
    out << "]" << std::endl;

    return out;
}

// 參考資料 : https://www.youtube.com/watch?v=YTnYte6U61w

/************************** Solution 1 BFS ver. **************************/
vector<vector<int>> updateMatrix_BFS(vector<vector<int>> &mat)
{
    const int rows = mat.size();
    const int cols = mat[0].size();
    queue<std::pair<int, int>> pending;
    vector<int> offset = {0, 1, 0, -1, 0};
    vector<vector<int>> res(rows, vector<int>(cols, INT_MAX));

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (mat[row][col] == 0)
            {
                pending.push(std::make_pair(row, col));
                res[row][col] = 0;
            }
        }
    }

    while (!pending.empty())
    {
        std::pair<int, int> cur = pending.front();
        pending.pop();
        int r = cur.first;
        int c = cur.second;
        for (int i = 0, j = 1; i < 4; i++, j++)
        {
            int new_r = r + offset[i];
            int new_c = c + offset[j];
            if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols)
            {
                if (res[new_r][new_c] > res[r][c] + 1)
                {
                    res[new_r][new_c] = res[r][c] + 1;
                    pending.push(std::make_pair(new_r, new_c));
                }
            }
        }
    }

    return res;
}
/************************** Solution 1 BFS ver. **************************/

/************************** Solution 2 DP ver. **************************/
vector<vector<int>> updateMatrix_DP(vector<vector<int>> &mat)
{
    const int rows = mat.size();
    const int cols = mat[0].size();
    vector<vector<int>> res(rows, vector<int>(cols, INT_MAX - 100000));

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (mat[row][col] == 0)
            {
                res[row][col] = 0;
            }
            else
            {
                if (row > 0)
                {
                    res[row][col] = std::min(res[row][col], res[row - 1][col] + 1);
                }

                if (col > 0)
                {
                    res[row][col] = std::min(res[row][col], res[row][col - 1] + 1);
                }
            }
        }
    }

    for (int row = rows - 1; row >= 0; row--)
    {
        for (int col = cols - 1; col >= 0; col--)
        {
            if (mat[row][col] == 0)
            {
                res[row][col] = 0;
            }
            else
            {
                if (row < rows - 1)
                {
                    res[row][col] = std::min(res[row][col], res[row + 1][col] + 1);
                }

                if (col < cols - 1)
                {
                    res[row][col] = std::min(res[row][col], res[row][col + 1] + 1);
                }
            }
        }
    }

    return res;
}
/************************** Solution 2 DP ver. **************************/

int main()
{
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    std::cout << updateMatrix_BFS(mat) << std::endl; // [[0,0,0],[0,1,0],[0,0,0]]

    mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    std::cout << updateMatrix_BFS(mat) << std::endl; // [[0,0,0],[0,1,0],[1,2,1]]

    mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    std::cout << updateMatrix_DP(mat) << std::endl; // [[0,0,0],[0,1,0],[0,0,0]]

    mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    std::cout << updateMatrix_DP(mat) << std::endl; // [[0,0,0],[0,1,0],[1,2,1]]
}