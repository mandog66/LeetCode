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
#include <stack>
#include <sstream>

using namespace std;

int strStr(string haystack, string needle)
{
    if (needle.size() > haystack.size())
        return -1;

    int index = 0;
    string clip = "";

    for (int i = 0; i < haystack.size(); i++)
    {
        index = i;
        for (int j = 0; j < needle.size(); j++)
        {
            clip += haystack[index++];
        }

        if (clip == needle)
            return i;
        else
            clip = "";

        if (index >= haystack.size())
            return -1;
    }

    return -1;
}

int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    cout << strStr(haystack, needle) << endl; // return 0

    haystack = "leetcode";
    needle = "leeto";
    cout << strStr(haystack, needle) << endl; // return -1

    haystack = "hello";
    needle = "ll";
    cout << strStr(haystack, needle) << endl; // return 2

    haystack = "abc";
    needle = "c";
    cout << strStr(haystack, needle) << endl; // return 2
}
