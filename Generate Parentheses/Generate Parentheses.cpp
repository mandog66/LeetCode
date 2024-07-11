#include <iostream>
#include <vector>
#include <string>
#include <queue>

using std::queue;
using std::string;
using std::vector;

bool is_valid(int ln, int rn, string s)
{
    if (s == ")" && rn < 0)
        return false;

    if (s == "(" && ln < 0)
        return false;

    return true;
}

void helper(int n, int ln, int rn, vector<string> &res, vector<string> offset, string comb)
{
    if (comb.size() == n * 2)
    {
        res.push_back(comb);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c < 2; c++)
        {
            comb += offset[c];
            ln = offset[c] == "(" ? ln - 1 : ln;
            rn = offset[c] == ")" ? rn - 1 : rn + 1;

            if (is_valid(ln, rn, offset[c]))
                helper(n, ln, rn, res, offset, comb);

            comb.pop_back();
            ln = offset[c] == "(" ? ln + 1 : ln;
            rn = offset[c] == ")" ? rn + 1 : rn - 1;
        }

        return;
    }

    return;
}

vector<string> generateParenthesis(int n)
{
    vector<string> offset = {"(", ")"};
    vector<string> res;

    /* Iteration */
    queue<std::pair<string, std::pair<int, int>>> todo;
    int ln = n, rn = 0;
    todo.push({"", {ln, rn}});

    while (!todo.empty())
    {
        string cur = todo.front().first;
        ln = todo.front().second.first;
        rn = todo.front().second.second;
        todo.pop();

        if (cur.size() == n * 2)
        {
            res.push_back(cur);
            continue;
        }

        for (int i = 0; i < 2; i++)
        {
            string c = offset[i];
            string comb = cur;
            comb += c;
            ln = c == "(" ? ln - 1 : ln;
            rn = c == ")" ? rn - 1 : rn + 1;

            if (rn >= 0 && ln >= 0)
                todo.push({comb, {ln, rn}});

            ln = c == "(" ? ln + 1 : ln;
            rn = c == ")" ? rn + 1 : rn - 1;
        }
    }

    return res;

    /* Recursion */
    // helper(n, n, 0, res, offset, {});
    // return res;
}

int main(int argc, char *argv[])
{
    int n = 3;
    vector<string> res = generateParenthesis(n);
    for (int i = 0; i < res.size(); i++)
        std::cout << (i == 0 ? "" : ", ") << res[i];
}