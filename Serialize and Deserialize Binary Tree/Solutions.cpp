#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using std::queue;
using std::string;
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

void serializeHelper(std::ostringstream &out, TreeNode *root)
{
    if (root)
    {
        out << root->val << ' ';
        serializeHelper(out, root->left);
        serializeHelper(out, root->right);
    }
    else
    {
        out << "# ";
    }
}

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    std::ostringstream out;
    serializeHelper(out, root);
    return out.str();
}

TreeNode *deserializeHelper(std::istringstream &in)
{
    string val;
    in >> val;

    if (val == "#")
        return nullptr;

    TreeNode *root = new TreeNode(std::stoi(val));
    root->left = deserializeHelper(in);
    root->right = deserializeHelper(in);

    return root;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    std::istringstream in(data);
    return deserializeHelper(in);
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