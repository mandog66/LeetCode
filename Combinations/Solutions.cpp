#include <iostream>
#include <vector>

using std::vector;

void backTrack(int n, int k, int c, vector<int> &comb, vector<vector<int>> &res)
{
    if (comb.size() == k)
    {
        res.push_back(comb);
        return;
    }

    for (int v = c; v <= n; v++)
    {
        comb.push_back(v);
        backTrack(n, k, v + 1, comb, res);
        comb.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> comb;
    backTrack(n, k, 1, comb, res);
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