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

class BSTIterator
{
private:
    vector<TreeNode *> inOrder;
    TreeNode *curr;
    int idx;

public:
    BSTIterator(TreeNode *root)
    {
        helper(root);
        curr = new TreeNode(-1);
        idx = 1;
    }

    void helper(TreeNode *root)
    {
        if (!root)
            return;

        helper(root->left);
        inOrder.push_back(root);
        helper(root->right);
    }

    int next()
    {
        if (curr->val == -1)
            curr = inOrder[0];
        else
            curr = inOrder[idx++];

        return curr->val;
    }

    bool hasNext()
    {
        return idx < inOrder.size() || curr->val == -1;
    }
};

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(7);
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(15);
    TreeNode *n3 = new TreeNode(9);
    TreeNode *n4 = new TreeNode(20);

    root->left = n1;
    root->right = n2;

    n2->left = n3;
    n2->right = n4;

    BSTIterator *tree = new BSTIterator(root);
    std::cout << tree->next() << std::endl;                         // 3
    std::cout << tree->next() << std::endl;                         // 7
    std::cout << (tree->hasNext() ? "True" : "False") << std::endl; // True
    std::cout << tree->next() << std::endl;                         // 9
    std::cout << (tree->hasNext() ? "True" : "False") << std::endl; // True
    std::cout << tree->next() << std::endl;                         // 15
    std::cout << (tree->hasNext() ? "True" : "False") << std::endl; // True
    std::cout << tree->next() << std::endl;                         // 20
    std::cout << (tree->hasNext() ? "True" : "False") << std::endl; // False
}