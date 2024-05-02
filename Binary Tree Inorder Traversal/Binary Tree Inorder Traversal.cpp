#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using std::stack;
using std::unordered_set;
using std::vector;

std::ostream &operator<<(std::ostream &out, const vector<int> &nums)
{
    out << "[";
    for (int i = 0; i < nums.size(); i++)
    {
        out << (i != 0 ? ", " : "") << nums[i];
    }
    out << "]" << std::endl;

    return out;
}

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTraversal_DFS(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;
    inorderTraversal_DFS(root->left, res);
    res.push_back(root->val);
    inorderTraversal_DFS(root->right, res);
}

vector<int> inorderTraversal(TreeNode *root)
{
    /* ********************* Implicit Stack ********************* */

    // if (root == NULL)
    //     return {};

    // if (root->left == nullptr && root->right == nullptr)
    //     return {root->val};

    // vector<int> res;
    // inorderTraversal_DFS(root, res);
    // return res;

    /* ********************* Implicit Stack ********************* */

    /* ********************* Explicit Stack ********************* */

    if (root == NULL)
        return {};

    if (root->left == nullptr && root->right == nullptr)
        return {root->val};

    unordered_set<TreeNode *> visited;
    stack<TreeNode *> stack;
    vector<int> res;
    stack.push(root);
    visited.insert(root);

    TreeNode *cur = stack.top();
    while (!stack.empty())
    {
        while (cur->left != nullptr && visited.find(cur->left) == visited.end())
        {
            cur = cur->left;
            stack.push(cur);
            visited.insert(cur);
        }

        if (cur->right != nullptr)
        {
            res.push_back(cur->val);
            stack.pop();
            cur = cur->right;
            stack.push(cur);
            visited.insert(cur);
        }
        else
        {
            res.push_back(cur->val);
            stack.pop();
            if (stack.empty())
                return res;
            cur = stack.top();
        }
    }

    return res;

    /* ********************* Explicit Stack ********************* */
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n8 = new TreeNode(8);
    TreeNode *n9 = new TreeNode(9);

    root->left = n2;
    root->right = n3;
    n2->left = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n4->right = n8;
    n5->left = n9;
    std::cout << inorderTraversal(root) << std::endl; // [4, 8, 2, 9, 5, 1, 6, 3, 7]
}
