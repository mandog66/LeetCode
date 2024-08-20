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

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Trie
{
private:
    TrieNode *root;
    int deep;

public:
    Trie(vector<string> &words)
    {
        deep = 0;
        root = new TrieNode();

        for (int i = 0; i < words.size(); i++)
        {
            string w = words[i];
            int size = w.size();

            deep = std::max(deep, size);
        }
    }

    vector<std::pair<int, int>> getCandidate(vector<vector<char>> &board, vector<vector<bool>> &vistied, int r, int c)
    {
        vector<int> offset = {1, 0, -1, 0, 1};
        vector<std::pair<int, int>> res;

        for (int i = 0, j = 1; i < 4; i++, j++)
        {
            int newRow = r + offset[i];
            int newCol = c + offset[j];

            if (newRow >= board.size() || newCol >= board[0].size() || vistied[newRow][newCol])
                continue;

            res.push_back(std::make_pair(newRow, newCol));
        }

        return res;
    }

    void insertHelper(vector<vector<char>> &board, vector<vector<bool>> &vistied, TrieNode *node, int r, int c, int d)
    {
        if (d > deep)
            return;

        int idx = board[r][c] - 'a';
        vector<std::pair<int, int>> candidate = getCandidate(board, vistied, r, c);

        if (!node->child[idx])
            node->child[idx] = new TrieNode();

        node = node->child[idx];

        for (int i = 0; i < candidate.size(); i++)
        {
            int newRow = candidate[i].first;
            int newCol = candidate[i].second;

            vistied[newRow][newCol] = true;
            insertHelper(board, vistied, node, newRow, newCol, d + 1);
            vistied[newRow][newCol] = false;
        }

        return;
    }

    void insert(vector<vector<char>> &board)
    {
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                int d = 1;
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

                visited[row][col] = true;
                insertHelper(board, visited, root, row, col, d);
            }
        }
    }

    bool findWords(string word)
    {
        TrieNode *curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';

            if (!curr->child[idx])
                return false;

            curr = curr->child[idx];
        }

        return true;
    }
};

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    Trie *trie = new Trie(words);
    vector<string> res;

    trie->insert(board);

    for (int i = 0; i < words.size(); i++)
    {
        string w = words[i];

        if (trie->findWords(w))
            res.push_back(w);
    }
    return res;
}

int main(int argc, char *argv[])
{
    vector<vector<char>> board = {{'a'}};
    vector<string> words = {"a"};
    vector<string> res = findWords(board, words); // {"a"}
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
    res = findWords(board, words); // {"eat", "oath"}
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
    res = findWords(board, words); // {"oath","eat","hklf","hf"}
    std::cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << (i == 0 ? "" : ", ") << res[i];
    }
    std::cout << "]" << std::endl;
}