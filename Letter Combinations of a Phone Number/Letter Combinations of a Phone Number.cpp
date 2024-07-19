#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::vector;

void backTrack(string digits, string combine, vector<string> &res, int idx, unordered_map<char, vector<char>> &offset)
{
    if (combine.size() == digits.size())
    {
        res.push_back(combine);
        return;
    }

    vector<char> candidate = offset[digits[idx]];

    for (int i = 0; i < candidate.size(); i++)
    {
        combine.push_back(candidate[i]);

        backTrack(digits, combine, res, idx + 1, offset);

        combine.pop_back();
    }

    return;
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};

    unordered_map<char, vector<char>> offset = {{'2', {'a', 'b', 'c'}},
                                                {'3', {'d', 'e', 'f'}},
                                                {'4', {'g', 'h', 'i'}},
                                                {'5', {'j', 'k', 'l'}},
                                                {'6', {'m', 'n', 'o'}},
                                                {'7', {'p', 'q', 'r', 's'}},
                                                {'8', {'t', 'u', 'v'}},
                                                {'9', {'w', 'x', 'y', 'z'}}};

    vector<string> res;
    backTrack(digits, "", res, 0, offset);
    return res;
}

int main(int argc, char *argv[])
{
    string digits = "23";
    vector<string> res = letterCombinations(digits);

    std::cout << "[";
    for (int i = 0; i < res.size(); i++)
        std::cout << (i == 0 ? "" : ", ") << res[i];
    std::cout << "]" << std::endl;
}