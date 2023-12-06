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

int lengthOfLastWord(string s)
{
    int res = 0;
    char space = ' ';
    int n = s.size();

    if (n == 1)
        return 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == space)
        {
            s.pop_back();
        }
        else
        {
            break;
        }
    }

    n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == space)
            return res;
        else
            res++;
    }
    return res;
}

int main()
{
    string s = "Hello World";
    cout << lengthOfLastWord(s) << endl; // return 5
    s = "   fly me   to   the moon  ";
    cout << lengthOfLastWord(s) << endl; // return 4
    s = "luffy is still joyboy";
    cout << lengthOfLastWord(s) << endl; // return 6
    s = "a";
    cout << lengthOfLastWord(s) << endl; // return 1
    s = "gay";
    cout << lengthOfLastWord(s) << endl; // return 3
}
