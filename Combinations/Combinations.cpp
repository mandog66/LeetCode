#include <iostream>
#include <vector>

using std::vector;

// vector<int> backTrack(int n, int k, int c, vector<int> comb, vector<int> visited, vector<vector<int>> &res)
// {
//     if (comb.size() == k)
//     {
//         res.push_back(comb);
//         return comb;
//     }

//     for (int i = c; i <= n; i++)
//     {
//         if (n - i < k)
//             return comb;

//         if (!visited[i])
//         {
//             comb.push_back(i);
//             visited[i] = 1;
//             comb = backTrack(n, k, i + 1, comb, visited, res);
//             comb.pop_back();
//             visited[i] = 0;
//         }
//     }

//     return comb;
// }

// vector<vector<int>> combine(int n, int k)
// {
//     vector<vector<int>> res;
//     vector<int> visited(n + 1, 0);
//     backTrack(n, k, 1, {}, visited, res);
//     return res;
// }

bool is_valid(int n, int k, int val, vector<int> comb, vector<int> visited)
{
    int box = k - comb.size();
    int v = n - val + 1;

    return !visited[val] && v >= box;
}

void backTrack(int n, int k, int c, vector<int> comb, vector<int> visited, vector<vector<int>> &res)
{
    if (comb.size() == k)
    {
        res.push_back(comb);
        return;
    }

    for (int v = c; v <= n; v++)
    {
        if (!is_valid(n, k, v, comb, visited))
            return;

        comb.push_back(v);
        visited[v] = 1;
        backTrack(n, k, v + 1, comb, visited, res);
        comb.pop_back();
        visited[v] = 0;
    }

    return;
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> visited(n + 1, 0);
    backTrack(n, k, 1, {}, visited, res);
    return res;
}

int main(int argc, char *argv[])
{
    int n = 4, k = 2;
    vector<vector<int>> res = combine(n, k);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
            std::cout << (j != 0 ? ", " : "") << res[i][j];

        std::cout << std::endl;
    }
}