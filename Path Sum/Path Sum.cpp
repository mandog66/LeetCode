#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode *node, int targetSum, bool &res, int sum)
{
    if (res)
        return;

    if (!node)
        return;

    sum += node->val;

    if (!node->left && !node->right)
        res = targetSum == sum;

    helper(node->left, targetSum, res, sum);
    helper(node->right, targetSum, res, sum);
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;

    if (!root->left && !root->right)
        return (root->val == targetSum ? true : false);

    bool res = false;
    helper(root, targetSum, res, 0);

    return res;
}

int main(int argc, char *argv[])
{
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n8 = new TreeNode(8);
    n5->left = n4;
    n5->right = n8;
    TreeNode *n11 = new TreeNode(11);
    n4->left = n11;
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n2 = new TreeNode(2);
    n11->left = n7;
    n11->right = n2;
    TreeNode *n13 = new TreeNode(13);
    TreeNode *_n4 = new TreeNode(4);
    n8->left = n13;
    n8->right = _n4;
    TreeNode *n1 = new TreeNode(1);
    _n4->right = n1;

    std::cout << (hasPathSum(n5, 22) ? "True" : "False") << std::endl;
}