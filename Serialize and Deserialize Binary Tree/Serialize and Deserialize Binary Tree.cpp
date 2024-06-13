#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using std::queue;
using std::string;
using std::unordered_map;
using std::vector;

std::ostream &operator<<(std::ostream &os, const vector<int> &v)
{
    os << "[";

    for (int i = 0; i < v.size(); i++)
    {
        os << (i != 0 ? ", " : "") << v[i];
    }

    os << "]";

    return os;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> levelOrder(TreeNode *root)
{
    queue<TreeNode *> todo;
    vector<int> res;

    todo.push(root);

    while (!todo.empty())
    {
        int size = todo.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *cur = todo.front();
            todo.pop();

            if (cur->left)
                todo.push(cur->left);

            if (cur->right)
                todo.push(cur->right);

            res.push_back(cur->val);
        }
    }

    return res;
}

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    if (!root)
        return "";

    queue<TreeNode *> todo;
    string res = "";

    todo.push(root);
    res += (std::to_string(root->val) + ",");

    while (!todo.empty())
    {
        int size = todo.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *cur = todo.front();
            todo.pop();

            if (cur->left)
            {
                todo.push(cur->left);
                res += (std::to_string(cur->left->val) + ",");
            }
            else
                res += "#,";

            if (cur->right)
            {
                todo.push(cur->right);
                res += (std::to_string(cur->right->val) + ",");
            }
            else
                res += "#,";
        }
    }

    return res;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data == "")
        return nullptr;

    unordered_map<char, char> offset = {{'l', 'r'}, {'r', 'l'}};

    string rootString = "";
    int idx = 0;
    while (data[idx] != ',')
    {
        rootString.push_back(data[idx]);
        idx++;
    }
    TreeNode *root = new TreeNode(std::stoi(rootString));
    queue<TreeNode *> todo;
    todo.push(root);
    todo.push(root);
    idx += 1;
    char flag = 'l';

    for (int i = idx; i < data.size(); i++)
    {
        TreeNode *newRoot = todo.front();
        todo.pop();

        if (data[i] != '#')
        {
            string num = "";
            while (data[i] != ',')
            {
                num.push_back(data[i++]);
            }

            if (flag == 'l')
            {
                TreeNode *newNode = new TreeNode(std::stoi(num));
                newRoot->left = newNode;
                todo.push(newNode);
                todo.push(newNode);
            }
            else
            {
                TreeNode *newNode = new TreeNode(std::stoi(num));
                newRoot->right = newNode;
                todo.push(newNode);
                todo.push(newNode);
            }
        }
        else
        {
            i += 1;
        }

        flag = offset[flag];
    }

    return root;
}

int main(int argc, char *argv[])
{
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    std::cout << "Serialize : " << serialize(n1) << std::endl;
    std::cout << "Deerialize : " << levelOrder(deserialize(serialize(n1))) << std::endl;

    // TreeNode *n1 = new TreeNode(1);
    // TreeNode *n2 = new TreeNode(2);
    // TreeNode *n2_ = new TreeNode(2);

    // n1->left = n2;
    // n1->right = n2_;

    // std::cout << "Serialize : " << serialize(n1) << std::endl;
    // std::cout << "Deerialize : " << levelOrder(deserialize(serialize(n1))) << std::endl;
}