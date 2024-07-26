#include <iostream>
#include <string>

using std::string;

class TrieNode
{
public:
    int score = 0;
    TrieNode *child[26];
};

class MapSum
{
public:
    int res;
    TrieNode *root;

    MapSum()
    {
        root = new TrieNode();
        res = 0;
    }

    void insert(string key, int val)
    {
        TrieNode *curr = root;

        for (int i = 0; i < key.size(); i++)
        {
            int idx = key[i] - 'a';

            if (!curr->child[idx])
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->score = val;
    }

    void helper(TrieNode *curr)
    {
        // 把該點的值初始化(更新)
        res += curr->score;

        for (int i = 0; i < 26; i++)
        {
            // 如果有子節點就把值加進去
            // 一般只有"字"才會有值，其餘為0
            if (curr->child[i])
                helper(curr->child[i]);
        }
    }

    int sum(string prefix)
    {
        res = 0;
        TrieNode *curr = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            int idx = prefix[i] - 'a';

            if (!curr->child[idx])
                return 0;

            curr = curr->child[idx];
        }

        helper(curr);

        return res;
    }

    void clear(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->child[i])
                clear(root->child[i]);
        }

        delete root;
        std::cout << "Delete Success" << std::endl;
    }

    ~MapSum()
    {
        clear(root);
    }
};

int main(int argc, char *argv[])
{
    MapSum *obj = new MapSum();
    obj->insert("apple", 3);
    std::cout << obj->sum("ap") << std::endl; // 3
    obj->~MapSum();

    obj = new MapSum();
    obj->insert("app", 2);
    obj->insert("apple", 2);
    std::cout << obj->sum("ap") << std::endl; // 4
    obj->~MapSum();
}