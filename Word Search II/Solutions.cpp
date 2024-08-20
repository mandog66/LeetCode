#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class TrieNode
{
public:
    TrieNode *child[26];
    string word;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        word = "";
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

    void insert(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            string w = words[i];
            TrieNode *curr = root;

            for (int j = 0; j < w.size(); j++)
            {
                int idx = w[j] - 'a';

                if (!curr->child[idx])
                    curr->child[idx] = new TrieNode();

                curr = curr->child[idx];
            }

            curr->word = w;
        }
    }

    void findWords(vector<vector<char>> &board, vector<string> &res, TrieNode *node, int r, int c)
    {
        char bc = board[r][c];

        if (!bc || !node->child[bc - 'a'])
            return;

        node = node->child[bc - 'a'];

        if (node->word.size() > 0)
        {
            res.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '\0'; // the NULL character, denoted by '\0'

        if (r > 0)
            findWords(board, res, node, r - 1, c);

        if (c > 0)
            findWords(board, res, node, r, c - 1);

        if (r < board.size() - 1)
            findWords(board, res, node, r + 1, c);

        if (c < board[0].size() - 1)
            findWords(board, res, node, r, c + 1);

        board[r][c] = bc;
    }

    TrieNode *getRoot()
    {
        return root;
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> res;
        Trie *trie = new Trie();

        trie->insert(words);

        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                trie->findWords(board, res, trie->getRoot(), row, col);
            }
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<char>> board = {{'a'}};
    vector<string> words = {"a"};
    Solution s;
    vector<string> res = s.findWords(board, words); // {"a"}
    std::cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << (i == 0 ? "" : ", ") << res[i];
    }
    std::cout << "]" << std::endl;

    board = {{'o', 'a', 'a', 'n'},
             {'e', 't', 'a', 'e'},
             {'i', 'h', 'k', 'r'},
             {'i', 'f', 'l', 'v'}};
    words = {"oath", "pea", "eat", "rain"};
    res = s.findWords(board, words); // {"eat", "oath"}
    std::cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << (i == 0 ? "" : ", ") << res[i];
    }
    std::cout << "]" << std::endl;

    board = {{'o', 'a', 'a', 'n'},
             {'e', 't', 'a', 'e'},
             {'i', 'h', 'k', 'r'},
             {'i', 'f', 'l', 'v'}};
    words = {"oath", "pea", "eat", "rain", "hklf", "hf"};
    res = s.findWords(board, words); // {"oath","eat","hklf","hf"}
    std::cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << (i == 0 ? "" : ", ") << res[i];
    }
    std::cout << "]" << std::endl;
}