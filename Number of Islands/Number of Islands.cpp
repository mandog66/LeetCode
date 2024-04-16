#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int numIslands(vector<vector<char>> &grid)
{
    int res = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            if (!visited[row][col] && grid[row][col] - '0')
            {
                q.push(make_pair(row, col));
                visited[row][col] = 1;

                while (!q.empty())
                {
                    if (q.front().first + 1 < grid.size() && !visited[q.front().first + 1][q.front().second] && grid[q.front().first + 1][q.front().second] - '0')
                    {
                        q.push(make_pair(q.front().first + 1, q.front().second));
                        visited[q.front().first + 1][q.front().second] = 1;
                    }

                    if (q.front().second + 1 < grid[0].size() && !visited[q.front().first][q.front().second + 1] && grid[q.front().first][q.front().second + 1] - '0')
                    {
                        q.push(make_pair(q.front().first, q.front().second + 1));
                        visited[q.front().first][q.front().second + 1] = 1;
                    }

                    if (q.front().first - 1 < grid.size() && !visited[q.front().first - 1][q.front().second] && grid[q.front().first - 1][q.front().second] - '0')
                    {
                        q.push(make_pair(q.front().first - 1, q.front().second));
                        visited[q.front().first - 1][q.front().second] = 1;
                    }

                    if (q.front().second - 1 < grid[0].size() && !visited[q.front().first][q.front().second - 1] && grid[q.front().first][q.front().second - 1] - '0')
                    {
                        q.push(make_pair(q.front().first, q.front().second - 1));
                        visited[q.front().first][q.front().second - 1] = 1;
                    }

                    q.pop();
                }

                res++;
            }
        }
    }

    return res;
}

int main()
{
    vector<vector<char>> grid = {
        {'0', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    cout << numIslands(grid) << endl; // 1

    grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << numIslands(grid) << endl; // 3
}
