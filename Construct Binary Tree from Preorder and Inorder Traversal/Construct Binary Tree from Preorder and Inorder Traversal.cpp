#include <iostream>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int preorderL, int preorderR, int inorderL, int inorderR, unordered_map<int, int> &index)
{
    if (preorderL > preorderR || inorderL > inorderR)
        return nullptr;

    int rootVal = preorder[preorderL];
    TreeNode *root = new TreeNode(rootVal);
    int rootIndex = index[rootVal];
    int leftSubtreeSize = rootIndex - inorderL;

    root->left = buildTreeHelper(preorder, inorder, preorderL + 1, preorderR - (inorderR - rootIndex), inorderL, rootIndex - 1, index);
    root->right = buildTreeHelper(preorder, inorder, preorderL + leftSubtreeSize + 1, preorderR, rootIndex + 1, inorderR, index);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> index;

    for (int i = 0; i < inorder.size(); i++)
        index[inorder[i]] = i;

    return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, index);
}

int main(int argc, char *argv[])
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    std::cout << buildTree(preorder, inorder)->val << std::endl;
}