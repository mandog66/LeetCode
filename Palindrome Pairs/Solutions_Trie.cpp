#include <iostream>
#include <vector>
#include <string>
#include <queue>

using std::queue;
using std::string;
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

class TrieNode
{
public:
    TrieNode *child[26];
    int index;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        index = -1;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string &word, int index)
    {
        TrieNode *curr = root;

        for (int i = word.size() - 1; i >= 0; i--)
        {
            int cIdx = word[i] - 'a';

            if (!curr->child[cIdx])
                curr->child[cIdx] = new TrieNode();

            curr = curr->child[cIdx];
        }

        curr->index = index;
    }

    vector<int> getIndices(TrieNode *curr)
    {
        vector<int> indices;
        queue<TrieNode *> bfs;
        bfs.push(curr);

        while (!bfs.empty())
        {
            TrieNode *temp = bfs.front();
            bfs.pop();

            if (temp->index != -1)
                indices.push_back(temp->index);

            for (int i = 0; i < 26; i++)
            {
                if (temp->child[i])
                    bfs.push(temp->child[i]);
            }
        }

        return indices;
    }

    TrieNode *getRoot()
    {
        return root;
    }
};

class Solution
{
private:
    vector<vector<int>> res;

public:
    bool isPalindrome(const string &s, int l, int r)
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
        Trie *trie = new Trie();
        const int n = words.size();

        // 建立 Trie，元素以倒著的方式插入
        for (int i = 0; i < n; i++)
            trie->insert(words[i], i);

        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            TrieNode *curr = trie->getRoot();
            int j = 0;

            /*
                這裡是要找出在 Trie 中有沒有存在一個"字"可以和 word 成為回文。
                Trie 跟 word 是相反的，所以 Trie 中的元素代表能夠與之成為回文。
                    word1 = "abcd"
                    word2 = "dcba" -> Trie = "abcd"
                    所以 word1 能夠和 word2 成為回文
            */
            for (; j < word.size() && curr; j++)
            {
                int cIdx = word[j] - 'a';

                /*
                    當 words 有空字串時觸發。
                    curr->index != -1 -> 空字串在 root 會不等於 -1
                    curr->index != i  -> 題目設定 i != j
                    isPalindrome(word, j, word.size() - 1) -> 判斷是否回文
                        這裡 j 不直接設定為 0，是因為判斷過的字母需要去除。

                        words = ["a","abc","aba",""]，word = "aba"
                        因為有空字串，所以 root 的 index 不為 0，因此第一次 if 為 true，
                        curr 到 a 節點，第二次 if 因為 a 剛好也存在，所以 curr->index 不為 0，
                        這時如果 j = 0，那就會發現第二次 if 會變成 true(錯誤，"abaa"不是回文)，
                        也就是說 j 必須設定成去除判斷過的字母。

                */
                if (curr->index != -1 && curr->index != i && isPalindrome(word, j, word.size() - 1))
                    res.push_back({i, curr->index});

                curr = curr->child[cIdx];
            }

            /*
                透過 Trie 可以知道目前有部分符合條件的字存在。
                    word1 = "lls"
                    word2 = "sssll" -> Trie = "llsss"
                    word2 有部分符合 word1 但 word2 還有子節點需要判斷(剩餘的部分，llsss -> ss)
                而剩餘的部分為 word2[0] ~ word2.size() - j - 1，j 可以想成是 word1 的長度，1 是轉換成 index。
            */
            if (curr)
            {
                vector<int> indices = trie->getIndices(curr);

                for (int k : indices)
                {
                    if (k != i && isPalindrome(words[k], 0, words[k].size() - j - 1))
                        res.push_back({i, k});
                }
            }
        }

        delete trie;

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