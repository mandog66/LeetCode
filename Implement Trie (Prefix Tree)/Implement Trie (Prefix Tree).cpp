#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Trie
{
public:
    Trie()
    {
        unordered_map<char, TrieNode *> child = {{' ', nullptr}};
        root = new TrieNode(false, child);
    }

    void insert(string word)
    {
        const int n = word.size();
        TrieNode *curRoot = root;

        for (int i = 0; i < n; i++)
        {
            char cur = word[i];

            if (curRoot->childNode.find(cur) == curRoot->childNode.end())
            {
                TrieNode *newNode = new TrieNode((i == word.size() - 1 ? true : false), {{' ', nullptr}});
                curRoot->childNode.insert(std::make_pair(cur, newNode));
            }

            curRoot = curRoot->childNode[cur];
        }

        curRoot->isWord = true;
    }

    bool search(string word)
    {
        const int n = word.size();
        TrieNode *curRoot = root;

        for (int i = 0; i < n; i++)
        {
            char cur = word[i];

            if (curRoot->childNode.find(cur) != curRoot->childNode.end())
                curRoot = curRoot->childNode[cur];
            else
                return false;
        }

        return curRoot->isWord;
    }

    bool startsWith(string prefix)
    {
        const int n = prefix.size();
        TrieNode *curRoot = root;

        for (int i = 0; i < n; i++)
        {
            char cur = prefix[i];

            if (curRoot->childNode.find(cur) != curRoot->childNode.end())
                curRoot = curRoot->childNode[cur];
            else
                return false;
        }

        return true;
    }

private:
    struct TrieNode
    {
        bool isWord;
        unordered_map<char, TrieNode *> childNode;
        TrieNode(bool w, unordered_map<char, TrieNode *> c)
        {
            isWord = w;
            childNode = c;
        };
    };

    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char *argv[])
{
    Trie *trie = new Trie();
    trie->insert("apple");
    std::cout << (trie->search("apple") ? "True" : "False") << std::endl;
    std::cout << (trie->search("app") ? "True" : "False") << std::endl;
    std::cout << (trie->startsWith("app") ? "True" : "False") << std::endl;
    trie->insert("app");
    std::cout << (trie->search("app") ? "True" : "False") << std::endl;
}