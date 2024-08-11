#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;

class TrieNode
{
public:
    bool endOfWord = false;
    int idx;
    TrieNode *child[26];
};

string replaceWords(vector<string> &dictionary, string sentence)
{
    TrieNode *root = new TrieNode();

    for (int idx = 0; idx < dictionary.size(); idx++)
    {
        TrieNode *curNode = root;
        string dict = dictionary[idx];

        for (char c : dict)
        {
            int cIdx = c - 'a';

            if (!curNode->child[cIdx])
                curNode->child[cIdx] = new TrieNode();
            curNode = curNode->child[cIdx];
        }

        curNode->endOfWord = true;
        curNode->idx = idx;
    }

    std::istringstream iss(sentence);

    string word, res = "";

    while (iss >> word)
    {
        TrieNode *curNode = root;

        for (int idx = 0; idx < word.size(); idx++)
        {
            int cIdx = word[idx] - 'a';

            if (curNode->child[cIdx])
            {
                if (idx == word.size() - 1)
                {
                    res += (word + " ");
                    break;
                }

                curNode = curNode->child[cIdx];

                if (curNode->endOfWord)
                {
                    res += (dictionary[curNode->idx] + " ");
                    break;
                }
            }
            else
            {
                res += (word + " ");
                break;
            }
        }
    }

    res.pop_back();
    return res;
}

int main(int argc, char *argv[])
{
    // vector<string> dictionary = {"catt", "bat", "rat", "ca", "capple"};
    // string sentence = "the cattle was rattled by the battery";
    // std::cout << replaceWords(dictionary, sentence) << std::endl;

    vector<string> dictionary = {"a", "aa", "aaa", "aaaa"};
    string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    std::cout << replaceWords(dictionary, sentence) << std::endl;
}