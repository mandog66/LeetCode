#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class TrieNode
{
public:
    int sum;
    bool isWord;
    TrieNode *children[26];

    TrieNode()
    {
        sum = 0;
        isWord = false;

        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;
    unordered_map<string, int> exist;

public:
    Trie()
    {
        root = new TrieNode();
        exist = unordered_map<string, int>();
    }

    void insert(string key, int val)
    {
        TrieNode *curNode = root;

        if (exist.find(key) == exist.end())
        {
            for (int i = 0; i < key.size(); i++)
            {
                int idx = key[i] - 'a';

                if (!curNode->children[idx])
                    curNode->children[idx] = new TrieNode();

                curNode = curNode->children[idx];
                curNode->sum += val;
            }

            exist[key] = val;
            curNode->isWord = true;
        }
        else
        {
            int oldVal = exist[key];
            exist[key] = val;

            for (int i = 0; i < key.size(); i++)
            {
                int idx = key[i] - 'a';

                curNode->children[idx]->sum = curNode->children[idx]->sum - oldVal + val;
                curNode = curNode->children[idx];
            }
        }
    }

    int search(string prefix)
    {
        TrieNode *curNode = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            int idx = prefix[i] - 'a';

            if (!curNode->children[idx])
                return 0;

            curNode = curNode->children[idx];
        }

        return curNode->sum;
    }

    ~Trie()
    {
        clear(root);
    }

    void clear(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
                clear(root->children[i]);
        }

        delete root;
    }
};

class MapSum
{
public:
    Trie *trie;

    MapSum()
    {
        trie = new Trie();
    }

    void insert(string key, int val)
    {
        trie->insert(key, val);
    }

    int sum(string prefix)
    {
        return trie->search(prefix);
    }

    ~MapSum()
    {
        trie->~Trie();
    }
};

int main(int argc, char *argv[])
{
    MapSum *obj = new MapSum();
    obj->insert("apple", 3);
    std::cout << obj->sum("ap") << std::endl; // 3

    obj->insert("app", 2);
    obj->insert("apple", 2);
    std::cout << obj->sum("ap") << std::endl; // 4
}