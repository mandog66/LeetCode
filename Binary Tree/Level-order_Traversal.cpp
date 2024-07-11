#include <iostream>
#include <vector>
#include <queue>

using std::queue;
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

std::ostream &operator<<(std::ostream &os, const vector<vector<int>> &v)
{
    os << "[";

    for (int row = 0; row < v.size(); row++)
    {
        os << "[";
        int s = v[row].size();

        for (int col = 0; col < s; col++)
        {
            os << (col != 0 ? ", " : "") << v[row][col];
        }

        os << (row != v.size() - 1 ? "], " : "]");
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

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (!root)
        return {{}};

    if (!root->left && !root->right)
        return {{root->val}};

    queue<TreeNode *> q;
    vector<vector<int>> res = {{root->val}};
    int childSize = 1;
    q.push(root);

    while (!q.empty())
    {
        int s = 0;
        vector<int> c;
        for (int node = 0; node < childSize; node++)
        {
            TreeNode *cur = q.front();
            q.pop();

            if (cur->left)
            {
                q.push(cur->left);
                s++;
                c.push_back(cur->left->val);
            }

            if (cur->right)
            {
                q.push(cur->right);
                s++;
                c.push_back(cur->right->val);
            }
        }

        res.push_back(c);
        childSize = s;
    }

    res.pop_back();
    return res;
}

vector<vector<int>> levelOrder_solution(TreeNode *root)
{
    queue<TreeNode *> todo;
    vector<vector<int>> res;

    todo.push(root);

    while (!todo.empty())
    {
        vector<int> level;
        int size = todo.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *cur = todo.front();
            todo.pop();

            if (cur->left)
                todo.push(cur->left);

            if (cur->right)
                todo.push(cur->right);

            level.push_back(cur->val);
        }

        res.push_back(level);
    }

    return res;
}

void helper(TreeNode *node, vector<vector<int>> &res, int level)
{
    if (!node)
        return;

    int curLevel = level;
    if (res.size() < curLevel + 1)
        res.push_back({node->val});
    else
        res[curLevel].push_back(node->val);

    helper(node->left, res, level + 1);
    helper(node->right, res, level + 1);
}

vector<vector<int>> levelOrder_recursion(TreeNode *root)
{
    vector<vector<int>> res;
    helper(root, res, 0);
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

    // std::cout << levelOrder(n6) << std::endl;
    // std::cout << levelOrder_solution(n6) << std::endl;
    std::cout << levelOrder_recursion(n6) << std::endl;
}