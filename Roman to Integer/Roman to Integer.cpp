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

int romanToInt(string s)
{
    unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int total = 0;
    int n = s.size();

    if (n == 1)
    {
        return roman[s[0]];
    }

    for (int i = 1; i < n; i++)
    {
        int first = roman[s[i - 1]];
        int second = roman[s[i]];
        if (first >= second)
        {
            total += first;
            if (i + 1 == n)
            {
                total += second;
            }
        }
        else
        {
            total += (second - first);
            i++;
            if (i == n - 1)
            {
                total += roman[s[i]];
            }
        }
    }
    return total;
}

int main()
{
    string s = "III";
    cout << romanToInt(s) << endl; // return 3
    s = "LVIII";
    cout << romanToInt(s) << endl; // return 58
    s = "MCMXCIV";
    cout << romanToInt(s) << endl; // return 1994
    s = "MDCXCV";
    cout << romanToInt(s) << endl; // return 1695
}
