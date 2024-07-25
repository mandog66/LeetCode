#include <iostream>
#include <string>

using std::string;

class TrieNode
{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode()
    {
        isWord = false;
        /*
            for (auto &a : child) 中的 & 是表示參考 child，即可以更改 child 的內容

            for (auto a : child) 中沒有 & 符號，a 只是單純把 child 的內容"複製"出來，並不會影響 child 的內容
            而且在遍歷時有複製的動作，所以執行速度會比有 & 符號慢
        */
        for (auto &a : child)
            a = nullptr;
    }
};
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string s)
    {
        TrieNode *p = root;
        for (auto &a : s)
        {
            int i = a - 'a';
            if (!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    bool search(string key, bool prefix = false)
    {
        TrieNode *p = root;
        for (auto &a : key)
        {
            int i = a - 'a';
            if (!p->child[i])
                return false;
            p = p->child[i];
        }
        if (prefix == false)
            return p->isWord;
        return true;
    }

    bool startsWith(string prefix)
    {
        return search(prefix, true);
    }

    ~Trie()
    {
        // Reference : https://learn.microsoft.com/zh-tw/cpp/cpp/destructors-cpp?view=msvc-170
        clear(root);
    }

    void clear(TrieNode *root)
    {
        for (auto &c : root->child)
        {
            if (c)
                clear(c);
        }

        delete root;
        std::cout << "destructor is working" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    Trie *trie = new Trie();
    trie->insert("apple");
    std::cout << (trie->search("apple") ? "True" : "False") << std::endl;
    std::cout << (trie->search("app") ? "True" : "False") << std::endl;
    std::cout << (trie->startsWith("app") ? "True" : "False") << std::endl;
    trie->insert("app");
    std::cout << (trie->search("app") ? "True" : "False") << std::endl;

    trie->~Trie();
}