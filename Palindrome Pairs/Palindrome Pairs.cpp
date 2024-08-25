#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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
    unordered_map<string, int> map;

public:
    Trie(vector<string> &words)
    {
        root = new TrieNode();

        for (int i = 0; i < words.size(); i++)
        {
            string w = words[i];

            map.insert({w, i});
        }
    }

    void buildTrie(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            string w = words[i];
            TrieNode *curr = root;

            for (char c : w)
            {
                int idx = c - 'a';

                if (!curr->child[idx])
                    curr->child[idx] = new TrieNode();

                curr = curr->child[idx];
            }

            curr->index = i;
        }
    }

    void palindromePairs(vector<string> &words, vector<vector<int>> &res)
    {
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == "")
                continue;

            string prefix = "";
            string suffix = words[i];
            TrieNode *curr = root;

            for (int idx = suffix.size() - 1; idx >= 0; idx--)
            {
                int cIdx = suffix[idx] - 'a';
                prefix += suffix[idx];

                if (curr->child[cIdx])
                    curr = curr->child[cIdx];
                else
                {
                    if (idx > 0 && prefix.back() == suffix[--idx])
                        prefix.pop_back();
                }
            }

            if (map.find(prefix) != map.end() && map[prefix] != i)
                res.push_back({map[prefix], i});

            if (root->index != -1 && prefix == suffix)
            {
                res.push_back({map[""], i});
                res.push_back({i, map[""]});
            }
        }
    }
};

class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        Trie *trie = new Trie(words);
        vector<vector<int>> res;

        trie->buildTrie(words);
        trie->palindromePairs(words, res);

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    std::cout << s.palindromePairs(words) << std::endl; // [[0,1],[1,0],[3,2],[2,4]]

    words = {"bat", "tab", "cat"};
    std::cout << s.palindromePairs(words) << std::endl; // [[0,1],[1,0]]

    words = {"a", ""};
    std::cout << s.palindromePairs(words) << std::endl; // [[0,1],[1,0]]
}