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
    /*
        hashmap<char, int> 代表 <字元, idx>

        利用[left, right]兩個指標來當作邊界，代表子字串。

        出現重複字元，left從重複的字元往前一步並更新hashmap。

        出現非重複字元，更新最大長度並將字元插入hashmap。
        這裡有一個重點，if敘述中有 "< left"，要表示一個情況。
        EX.
            s = tmmzuxt

            當right = s.size() - 1時，是重複字元，要是沒有上述if的判斷
            這時 left 會被更新成1(更新前為2)，邊界反而變大，所以才有上述
            if的敘述。
    */
    int left = 0;
    int maxLength = 0;
    unordered_map<char, int> hashmap;

    for (int right = 0; right < s.size(); right++)
    {
        if (!hashmap.count(s[right]) || hashmap[s[right]] < left)
        {
            maxLength = max(maxLength, right - left + 1);
            hashmap[s[right]] = right;
        }
        else
        {
            left = hashmap[s[right]] + 1;
            hashmap[s[right]] = right;
        }
    }

    return maxLength;
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
