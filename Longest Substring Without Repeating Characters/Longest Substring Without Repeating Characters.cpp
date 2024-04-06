#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::cout;
using std::endl;
using std::max;
using std::string;
using std::unordered_map;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> hashmap;
    string res = "";
    int resSize = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (hashmap[s[i]] == 1)
        {
            resSize = max(int(res.size()), resSize);
            if (find(res.begin(), res.end(), s[i]) != res.end())
            {
                for (int idx = 0; idx < (find(res.begin(), res.end(), s[i]) + 1) - res.begin(); idx++)
                {
                    hashmap.erase(res[idx]);
                }

                res.erase(res.begin(), find(res.begin(), res.end(), s[i]) + 1);
            }
            else
            {
                res = "";
                hashmap.clear();
            }

            hashmap[s[i]]++;
            res += s[i];
        }
        else
        {
            hashmap[s[i]]++;
            res += s[i];
        }
    }

    return max(int(res.size()), resSize);
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl; // 3

    s = "pwwkew";
    cout << lengthOfLongestSubstring(s) << endl; // 3

    s = "aab";
    cout << lengthOfLongestSubstring(s) << endl; // 2

    s = "";
    cout << lengthOfLongestSubstring(s) << endl; // 0

    s = " ";
    cout << lengthOfLongestSubstring(s) << endl; // 1

    s = "dvdf";
    cout << lengthOfLongestSubstring(s) << endl; // 3

    s = "tmmzuxt";
    cout << lengthOfLongestSubstring(s) << endl; // 5
}
