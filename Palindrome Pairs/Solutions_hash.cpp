#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using std::map;
using std::string;
using std::unordered_map;
using std::vector;

std::ostream &operator<<(std::ostream &os, const vector<vector<int>> &res)
{
    const int n = res.size();
    const int m = res[0].size();

    os << "[";
    for (int i = 0; i < n; i++)
    {
        os << "[";

        for (int j = 0; j < m; j++)
        {
            os << (j != 0 ? ", " : "") << res[i][j];
        }

        os << (i != n - 1 ? "], " : "]");
    }
    os << "]";

    return os;
}

class Solution
{
private:
public:
    bool isPalindrome(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        map<int, unordered_map<string, int>> mm;

        for (int i = 0; i < words.size(); i++)
            mm[words[i].size()][string(words[i].rbegin(), words[i].rend())] = i;

        vector<vector<int>> res;

        for (int i = 0; i < words.size(); i++)
        {
            string w = words[i];

            // C++ 17 新增的功能
            // Structured Bindings
            // 利用 [] 來使用 tuple-like 容器
            for (auto &[k, m] : mm)
            {
                /*
                    k is the length of the word
                    m is unordered_map
                */
                if (k == w.size())
                {
                    if (m.count(w) && m[w] != i)
                        res.push_back({i, m[w]});
                    break;
                }

                if (isPalindrome(w, k, w.size() - 1))
                {
                    /*
                        w 被當作前綴
                        k 被當作後綴長度

                        如果要成為回文，w 的前 k 個字母必須相同(subWord)，
                        也就是說，w 剩餘的字母如果是回文就會觸發這個 if，
                        再加上 wubWord 也存在的話即為解答。
                            w = "abcd"，k = 3

                            => subWord = "abc"，在 map 中是相反儲存所以原文是 "cba"
                            => 組合"abcd" + "cba"
                    */
                    string subWord = w.substr(0, k);

                    if (m.count(subWord))
                        // w 的前 k 個字母存在
                        res.push_back({i, m[subWord]});
                }

                if (isPalindrome(w, 0, w.size() - k - 1))
                {
                    /*
                        w 被當作後綴
                        k 被當作前綴長度

                        如果要成為回文，w 的後 k 個字母必須相同(subWord)，
                        也就是說，w 剩餘的字母如果是回文就會觸發這個 if
                        再加上 wubWord 也存在的話即為解答。
                            w = "abcd"，k = 3

                            => subWord = "bcd"，在 map 中是相反儲存所以原文是 "dcb"
                            => 組合"dcb" + "abcd"
                    */
                    string subWord = w.substr(w.size() - k);

                    if (m.count(subWord))
                        res.push_back({m[subWord], i});
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s1, s2, s3;
    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    std::cout << s1.palindromePairs(words) << std::endl; // [[0,1],[1,0],[3,2],[2,4]]

    words = {"bat", "tab", "cat"};
    std::cout << s2.palindromePairs(words) << std::endl; // [[0,1],[1,0]]

    words = {"a", ""};
    std::cout << s3.palindromePairs(words) << std::endl; // [[0,1],[1,0]]
}