#include <iostream>
#include <stack>

using std::stack;

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
    stack<TreeNode *> s;

public:
    BSTIterator(TreeNode *root)
    {
        partialInorder(root);
    }

    void partialInorder(TreeNode *root)
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *top = s.top();
        s.pop();

        partialInorder(top->right);

        return top->val;
    }

    bool hasNext()
    {
        return !s.empty();
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