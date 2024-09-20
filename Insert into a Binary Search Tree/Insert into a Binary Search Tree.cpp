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

std::ostream &operator<<(std::ostream &os, TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *curr = root;

    while (curr != NULL)
    {
        s.push(curr);
        curr = curr->left;
    }

    while (!s.empty())
    {
        TreeNode *top = s.top();
        s.pop();

        TreeNode *r = top->right;

        while (r != NULL)
        {
            s.push(r);
            r = r->left;
        }

        os << top->val << " ";
    }

    return os;
}

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    // if (!root)
    // {
    //     TreeNode *newNode = new TreeNode(val);

    //     return newNode;
    // }

    // TreeNode *curr = root;

    // if (val > curr->val)
    //     curr->right = insertIntoBST(curr->right, val);
    // else
    //     curr->left = insertIntoBST(curr->left, val);

    // return root;

    /*************************************************/

    TreeNode *curr = root;
    TreeNode *newNode = new TreeNode(val);

    if (!root)
        return newNode;

    while (curr)
    {
        if (val > curr->val)
        {
            if (!curr->right)
            {
                curr->right = newNode;
                curr = nullptr;
            }
            else
                curr = curr->right;
        }
        else
        {
            if (!curr->left)
            {
                curr->left = newNode;
                curr = nullptr;
            }
            else
                curr = curr->left;
        }
    }

    return root;
}

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(4);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(7);
    TreeNode *n3 = new TreeNode(1);
    TreeNode *n4 = new TreeNode(3);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    std::cout << insertIntoBST(root, 5) << std::endl;
}