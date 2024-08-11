#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;

class Trie
{
public:
    Trie *children[26];
    bool isEnd;

    Trie()
    {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEnd = false;
    }
};

class Solution
{
public:
    Trie *root;

    Solution()
    {
        root = new Trie();
    }

    void insert(string word)
    {
        // 建立 Trie
        Trie *node = root;

        for (char c : word)
        {
            int i = c - 'a';

            if (node->children[i] == nullptr)
                node->children[i] = new Trie();

            node = node->children[i];
        }

        node->isEnd = true;
    }

    string search(string word)
    {
        // 找尋符合條件的字根
        Trie *node = root;
        string res;

        for (char c : word)
        {
            int i = c - 'a';

            if (node->children[i] == nullptr)
                return word;

            res += c;

            if (node->children[i]->isEnd)
                return res;

            node = node->children[i];
        }

        return word;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        // 替換符合條件的字根
        for (string word : dictionary)
            insert(word);

        std::stringstream ss(sentence);
        string word, res;

        while (ss >> word)
        {
            if (!res.empty())
                res += " ";

            res += search(word);
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    // vector<string> dictionary = {"catt", "bat", "rat", "ca", "capple"};
    // string sentence = "the cattle was rattled by the battery";
    // Solution *res = new Solution();

    // std::cout << res->replaceWords(dictionary, sentence) << std::endl;

    vector<string> dictionary = {"a", "aa", "aaa", "aaaa"};
    string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    Solution *res = new Solution();

    std::cout << res->replaceWords(dictionary, sentence) << std::endl;
}