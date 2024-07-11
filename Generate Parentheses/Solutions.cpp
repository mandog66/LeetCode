#include <iostream>
#include <vector>
#include <string>
#include <queue>

using std::queue;
using std::string;
using std::vector;

void helper(int n, int open, int close, string comb, vector<string> &res)
{
    if (comb.length() == 2 * n)
    {
        res.push_back(comb);
        return;
    }

    if (open < n)
        helper(n, open + 1, close, comb + "(", res);

    if (close < open)
        helper(n, open, close + 1, comb + ")", res);
}

vector<string> generateParenthesis(int n)
{
    /* Iteration */
    queue<std::pair<string, std::pair<int, int>>> todo;
    vector<string> res;
    todo.push({"", {0, 0}});

    while (!todo.empty())
    {
        string combine = todo.front().first;
        int open = todo.front().second.first;
        int close = todo.front().second.second;
        todo.pop();

        if (combine.length() == n * 2)
        {
            res.push_back(combine);
            continue;
        }

        if (open < n)
            todo.push({combine + "(", {open + 1, close}});

        if (close < open)
            todo.push({combine + ")", {open, close + 1}});
    }

    return res;

    /* Recursion */
    // vector<string> res;
    // helper(n, 0, 0, "", res);
    // return res;
}

int main(int argc, char *argv[])
{
    int n = 3;
    vector<string> res = generateParenthesis(n);
    for (int i = 0; i < res.size(); i++)
        std::cout << (i == 0 ? "" : ", ") << res[i];
}