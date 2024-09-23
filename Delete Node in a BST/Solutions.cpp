#include <iostream>
#include <stack>
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

std::ostream &operator<<(std::ostream &os, TreeNode *root)
{
    using namespace std;

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

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;

        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
        {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else
            {
                TreeNode *curr = root->right;

                while (curr->left)
                    curr = curr->left;

                root->val = curr->val;
                root->right = deleteNode(root->right, root->val);
            }
        }

        return root;
    }
};

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(7);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(1);
    TreeNode *n4 = new TreeNode(6);
    TreeNode *n5 = new TreeNode(10);
    TreeNode *n6 = new TreeNode(4);
    TreeNode *n7 = new TreeNode(5);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->right = n5;

    n4->left = n6;

    n6->right = n7;

    Solution *s = new Solution();
    std::cout << s->deleteNode(root, 2) << std::endl;
}