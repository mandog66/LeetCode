#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using std::stack;
using std::unordered_set;
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(vector<int> &res, TreeNode *node)
{
    if (node == nullptr)
        return;

    res.push_back(node->val);
    helper(res, node->left);
    helper(res, node->right);
}

vector<int> recursive(TreeNode *root)
{
    vector<int> res;
    helper(res, root);
    return res;
}

vector<int> iterative(TreeNode *root)
{
    if (!root)
        return {};

    if (!root->left && !root->right)
        return {root->val};

    vector<int> res;
    stack<TreeNode *> s;
    unordered_set<TreeNode *> visited;
    s.push(root);
    visited.insert(root);
    res.push_back(root->val);

    TreeNode *cur = s.top();
    while (!s.empty())
    {
        while (cur->left && visited.find(cur->left) == visited.end())
        {
            cur = cur->left;
            s.push(cur);
            visited.insert(cur);
            res.push_back(cur->val);
        }

        if (cur->right)
        {
            s.pop();
            cur = cur->right;
            s.push(cur);
            visited.insert(cur);
            res.push_back(cur->val);
        }
        else
        {
            s.pop();
            if (s.empty())
                return res;
            cur = s.top();
        }
    }

    return res;
}

vector<int> iterative_solution(TreeNode *root)
{
    if (!root)
        return {};

    stack<TreeNode *> s;
    vector<int> res;

    s.push(root);
    while (!s.empty())
    {
        TreeNode *cur = s.top();
        s.pop();

        if (cur->right)
            s.push(cur->right);

        if (cur->left)
            s.push(cur->left);

        res.push_back(cur->val);
    }

    return res;
}

int main(int argc, char *argv[])
{
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n8 = new TreeNode(8);
    TreeNode *n9 = new TreeNode(9);

    n6->left = n2;
    n6->right = n7;
    n2->left = n1;
    n2->right = n4;
    n4->left = n3;
    n4->right = n5;
    n7->right = n9;
    n9->left = n8;

    std::cout << iterative(n6) << std::endl;
    std::cout << recursive(n6) << std::endl;
    std::cout << iterative_solution(n6) << std::endl;
}