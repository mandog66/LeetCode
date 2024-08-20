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
    bool isWord;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        isWord = false;
    }
};

class Trie
{
private:
    TrieNode *root;
    vector<int> offset;

public:
    Trie(vector<string> &words)
    {
        root = new TrieNode();
        offset = {1, 0, -1, 0, 1};
    }

    void insert(string word)
    {
        TrieNode *curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';

            if (!curr->child[idx])
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->isWord = true;
    }

    // vector<std::pair<int, int>> getCandidate(vector<vector<char>> &board, vector<vector<bool>> &vistied, TrieNode *node, int r, int c)
    // {
    //     vector<int> offset = {1, 0, -1, 0, 1};
    //     vector<std::pair<int, int>> res;

    //     for (int i = 0, j = 1; i < 4; i++, j++)
    //     {
    //         int newRow = r + offset[i];
    //         int newCol = c + offset[j];

    //         if (newRow >= board.size() || newCol >= board[0].size() || vistied[newRow][newCol])
    //             continue;

    //         int cIdx = board[newRow][newCol] - 'a';

    //         if (node->child[cIdx])
    //             res.push_back(std::make_pair(newRow, newCol));
    //     }

    //     return res;
    // }

    bool isValid(int r, int c, int n, int m)
    {
        return (r >= 0 && c >= 0 && r < n && c < m);
    }

    void helper(vector<vector<char>> &board, vector<vector<bool>> &vistied, vector<string> &res, TrieNode *node, string combine, int r, int c)
    {
        if (node->isWord)
        {
            res.push_back(combine);
            node->isWord = false;
        }

        for (int i = 0, j = 1; i < 4; i++, j++)
        {
            int newRow = r + offset[i];
            int newCol = c + offset[j];

            if (isValid(newRow, newCol, board.size(), board[0].size()) && node->child[board[newRow][newCol] - 'a'] && !vistied[newRow][newCol])
            {
                vistied[newRow][newCol] = true;
                combine += board[newRow][newCol];

                helper(board, vistied, res, node->child[board[newRow][newCol] - 'a'], combine, newRow, newCol);

                vistied[newRow][newCol] = false;
                combine.pop_back();
            }
        }

        // TrieNode *temp = node;

        // for (int i = 0; i < candidate.size(); i++)
        // {
        //     int newRow = candidate[i].first;
        //     int newCol = candidate[i].second;

        //     vistied[newRow][newCol] = true;
        //     node = node->child[board[newRow][newCol] - 'a'];
        //     combine += board[newRow][newCol];

        //     helper(board, vistied, getCandidate(board, vistied, node, newRow, newCol), res, node, combine, newRow, newCol);

        //     vistied[newRow][newCol] = false;
        //     node = temp;
        //     combine.pop_back();
        // }

        // return;
    }

    vector<string> findWords(vector<vector<char>> &board)
    {
        vector<string> res;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                if (root->child[board[row][col] - 'a'])
                {
                    string combine = "";
                    // vector<std::pair<int, int>> candidate = getCandidate(board, visited, root->child[board[row][col] - 'a'], row, col);

                    // if (root->child[board[row][col] - 'a']->isWord)
                    // {
                    //     res.push_back(combine + board[row][col]);
                    //     root->child[board[row][col] - 'a']->isWord = false;
                    // }

                    combine += board[row][col];
                    visited[row][col] = true;

                    helper(board, visited, res, root->child[board[row][col] - 'a'], combine, row, col);

                    combine.pop_back();
                    visited[row][col] = false;
                }
            }
        }

        return res;
    }
};

class Solution
{
public:
    /*
        這題差一點點成功。以原本自己寫的code會是TLE，測試是成功的但就是花比較多的時間。

        瓶頸在於我寫的選出"候選人"的地方，我的想法是 backtracking 需要 candidate，
        所以我另外寫一個 func 包含選出"候選人"和判斷是否為有效座標(row and col)，
        然後將"候選人"清單回傳。這樣做有一個問題，判斷候選人另外寫出來後回傳再去迭代是多
        餘的，因為這樣會產生更多的迭代次數，其實只要將選出候選人直接寫在 backtracking 的
        func 裡面就好，改成這樣就能解題。

        解答中，還有在 TrieNode 中包含 word 的變數，目的是如果該 word 是有效答案，可以
        直接寫入 res 不用像我的 code 還要組合字元，讓 code 變簡潔一點。

        在另一個我寫的 code(Word Search II_new.cpp) 作法是將 board 建立成 Trie(原本是 words)，這樣做還是會TLE。
    */
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *trie = new Trie(words);
        for (int i = 0; i < words.size(); i++)
            trie->insert(words[i]);

        return trie->findWords(board);
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