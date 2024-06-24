#include <iostream>
#include <vector>

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

vector<TreeNode *> generate(int left, int right)
{
    if (left == right)
    {
        TreeNode *node = new TreeNode(left);
        return {node};
    }

    if (left > right)
        return {nullptr};

    vector<TreeNode *> res;

    // 根節點
    for (int i = left; i <= right; i++)
    {
        // 在這個根節點所有可能的左子樹
        for (auto leftTree : generate(left, i - 1))
        {
            // 在這個根節點所有可能的右子樹
            for (auto rightTree : generate(i + 1, right))
            {
                TreeNode *root = new TreeNode(i, leftTree, rightTree);
                res.push_back(root);
            }
        }
    }

    return res;
}

vector<TreeNode *> generateTrees(int n)
{
    return generate(1, n);
}

vector<TreeNode *> generate_(int left, int right)
{
    if (left > right)
        return {nullptr};

    vector<TreeNode *> res;

    for (int i = left; i <= right; i++)
    {
        vector<TreeNode *> leftTrees = generate_(left, i - 1);
        vector<TreeNode *> rightTrees = generate_(i + 1, right);

        for (TreeNode *leftNode : leftTrees)
        {
            for (TreeNode *rightNode : rightTrees)
            {
                TreeNode *node = new TreeNode(i);
                node->left = leftNode;
                node->right = rightNode;
                res.push_back(node);
            }
        }
    }

    return res;
}

vector<TreeNode *> generateTrees_(int n)
{
    return generate_(1, n);
}

int main(int argc, char *argv[])
{
    int n = 3;
    std::cout << generateTrees(n).size() << std::endl;  // 5
    std::cout << generateTrees_(n).size() << std::endl; // 5
}