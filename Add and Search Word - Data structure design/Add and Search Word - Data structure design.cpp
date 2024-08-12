#include <iostream>
#include <string>
#include <queue>

using std::queue;
using std::string;

class Trie
{
public:
    Trie *childres[26];
    bool isEnd;

    Trie()
    {
        for (int i = 0; i < 26; i++)
            childres[i] = nullptr;

        isEnd = false;
    }
};

class WordDictionary
{
public:
    Trie *root;

    WordDictionary()
    {
        root = new Trie();
    }

    void addWord(string word)
    {
        Trie *curNode = root;

        for (char c : word)
        {
            int cIdx = c - 'a';

            if (!curNode->childres[cIdx])
                curNode->childres[cIdx] = new Trie();

            curNode = curNode->childres[cIdx];
        }

        curNode->isEnd = true;

        return;
    }

    bool search(string word)
    {
        queue<Trie *> candidates;
        candidates.push(root);

        for (char c : word)
        {
            int size = candidates.size();

            if (c == '.')
            {
                for (int i = 0; i < size; i++)
                {
                    Trie *node = candidates.front();
                    candidates.pop();

                    for (int j = 0; j < 26; j++)
                    {
                        if (node->childres[j])
                            candidates.push(node->childres[j]);
                    }
                }
            }
            else
            {
                int cIdx = c - 'a';

                for (int i = 0; i < size; i++)
                {
                    Trie *node = candidates.front();
                    candidates.pop();

                    if (node->childres[cIdx])
                        candidates.push(node->childres[cIdx]);
                }
            }

            if (candidates.empty())
                return false;
        }

        while (!candidates.empty())
        {
            Trie *node = candidates.front();
            candidates.pop();

            if (node->isEnd)
                return true;
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    // WordDictionary *wordDict = new WordDictionary();
    // wordDict->addWord("bad");
    // wordDict->addWord("dad");
    // wordDict->addWord("mad");
    // std::cout << (wordDict->search("pad") ? "True" : "False") << std::endl; // False
    // std::cout << (wordDict->search("bad") ? "True" : "False") << std::endl; // True
    // std::cout << (wordDict->search(".ad") ? "True" : "False") << std::endl; // True
    // std::cout << (wordDict->search("b..") ? "True" : "False") << std::endl; // True

    WordDictionary *wordDict = new WordDictionary();
    wordDict->addWord("at");
    wordDict->addWord("and");
    wordDict->addWord("an");
    wordDict->addWord("add");
    std::cout << (wordDict->search("a") ? "True" : "False") << std::endl;   // False
    std::cout << (wordDict->search(".at") ? "True" : "False") << std::endl; // False
    wordDict->addWord("bat");
    std::cout << (wordDict->search(".at") ? "True" : "False") << std::endl;  // True
    std::cout << (wordDict->search("an.") ? "True" : "False") << std::endl;  // True
    std::cout << (wordDict->search("a.d.") ? "True" : "False") << std::endl; // False
    std::cout << (wordDict->search("b.") ? "True" : "False") << std::endl;   // False
    std::cout << (wordDict->search("a.d") ? "True" : "False") << std::endl;  // True
    std::cout << (wordDict->search(".") ? "True" : "False") << std::endl;    // False
}