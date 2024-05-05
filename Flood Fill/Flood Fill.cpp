#include <iostream>
#include <vector>

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

void floodFill_Recursion(vector<vector<int>> &image, vector<vector<int>> &res, vector<vector<int>> &visited, int sr, int sc, int color, int cColor)
{

    if (sr < 0 || sr == image.size() || sc < 0 || sc == image[0].size() || visited[sr][sc] == 1)
        return;

    if (image[sr][sc] != cColor)
        return;

    res[sr][sc] = color;
    visited[sr][sc] = 1;

    floodFill_Recursion(image, res, visited, sr + 1, sc, color, cColor);
    floodFill_Recursion(image, res, visited, sr - 1, sc, color, cColor);
    floodFill_Recursion(image, res, visited, sr, sc + 1, color, cColor);
    floodFill_Recursion(image, res, visited, sr, sc - 1, color, cColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> res = image;
    vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
    int cColor = image[sr][sc];
    floodFill_Recursion(image, res, visited, sr, sc, color, cColor);
    return res;
}

int main()
{
    vector<vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
    int sr = 0, sc = 0, color = 0;
    std::cout << floodFill(image, sr, sc, color) << std::endl; // [[0,0,0],[0,0,0]]

    image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    sr = 1;
    sc = 1;
    color = 2;
    std::cout << floodFill(image, sr, sc, color) << std::endl; // [[2,2,2],[2,2,0],[2,0,1]]
}