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

TreeNode *buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int inorderL, int inorderR, int postorderL, int postorderR, unordered_map<int, int> &index)
{
    /*
        根據父節點尋找子樹在 inorder 和 postorder 的邊界
    */

    if (inorderL > inorderR || postorderL > postorderR)
        return nullptr;

    int rootVal = postorder[postorderR]; // 根節點會是最後一個元素
    TreeNode *root = new TreeNode(rootVal);
    int inorderRootIndex = index[rootVal];             // 根節點在 inorder 的位置
    int leftSubtreeSize = inorderRootIndex - inorderL; // 左子樹節點個數

    root->left = buildTreeHelper(inorder, postorder, inorderL, inorderRootIndex - 1, postorderL, postorderL + leftSubtreeSize - 1, index);
    root->right = buildTreeHelper(inorder, postorder, inorderRootIndex + 1, inorderR, postorderL + leftSubtreeSize, postorderR - 1, index);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    // 目的是將時間複雜度降低 : O(n ^ 2) --> O(n)
    unordered_map<int, int> index;

    for (int i = 0; i < inorder.size(); i++)
        // index[inorder 的元素] = 元素的位置
        index[inorder[i]] = i;

    return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, index);
}

int main(int argc, char *argv[])
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    std::cout << buildTree(inorder, postorder)->val << std::endl;

    // vector<int> inorder = {2, 1};
    // vector<int> postorder = {2, 1};
    // std::cout << buildTree(inorder, postorder)->val << std::endl;
}