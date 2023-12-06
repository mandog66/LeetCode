#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <cstdlib>
#include <time.h>
#include <unordered_map>
#include <array>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    string res = "";
    int index = 0;
    char label;
    bool lastChar = false;

    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            if (strs[i] == "")
                return "";

            label = strs[0][index];

            if (strs[i][index] != label)
                return res;

            if (index == strs[i].size() - 1)
                lastChar = true;
        }

        res += label;

        if (lastChar)
            break;

        index++;
    }

    return res;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl; // return "fl"
    strs = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs) << endl; // return ""
    strs = {""};
    cout << longestCommonPrefix(strs) << endl; // return ""
}
