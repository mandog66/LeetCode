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

void maxDepth_preorder(TreeNode *node, int depth, int &res)
{
    if (!node)
        return;

    if (!node->left && !node->right)
        res = std::max(res, depth);

    maxDepth_preorder(node->left, depth + 1, res);
    maxDepth_preorder(node->right, depth + 1, res);
}

int maxDepth_postorder(TreeNode *node)
{
    if (!node)
        return 0;

    int left_depth = maxDepth_postorder(node->left);
    int right_depth = maxDepth_postorder(node->right);

    return std::max(left_depth, right_depth) + 1;
}

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;

    /********************* Top-down *********************/
    // int res = 1;
    // maxDepth_preorder(root, 1, res);
    // return res;
    /********************* Top-down *********************/

    /********************* Bottom-up *********************/
    return maxDepth_postorder(root);
    /********************* Bottom-up *********************/
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

    std::cout << maxDepth(n6) << std::endl;
}