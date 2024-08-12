#include <iostream>
#include <string>

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
        return search(word, root);
    }

private:
    bool search(string word, Trie *node)
    {
        for (int i = 0; word[i] && node; i++)
        {
            if (word[i] == '.')
            {
                Trie *temp = node;

                for (int c = 0; c < 26; c++)
                {
                    node = temp->childres[c];

                    // string.substr(pos, len) -> 擷取部分字串
                    // https://cplusplus.com/reference/string/string/substr/
                    if (search(word.substr(i + 1), node))
                        return true;
                }
            }
            else
            {
                node = node->childres[word[i] - 'a'];
            }
        }

        return node && node->isEnd;
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