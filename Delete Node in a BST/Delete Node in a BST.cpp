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
private:
    TreeNode *parent;

public:
    Solution()
    {
        parent = new TreeNode();
    }

    TreeNode *findTarget(TreeNode *root, int key)
    {
        TreeNode *curr = root;

        while (curr && curr->val != key)
        {
            parent = curr;

            if (key > curr->val)
                curr = curr->right;
            else
                curr = curr->left;
        }

        return curr;

        // if (!root || key == root->val)
        //     return root;

        // if (key > root->val)
        //     return findTarget(root->right, key);
        // else
        //     return findTarget(root->left, key);
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root && root->val == key && !root->left && !root->right)
            return nullptr;

        TreeNode *curr = findTarget(root, key);

        if (root && curr)
        {
            if (curr->left && curr->right)
            {
                parent = curr;
                curr = curr->right;

                if (!curr->left)
                {
                    TreeNode *currRight = curr->right;
                    std::swap(parent->val, curr->val);
                    parent->right = currRight;
                }
                else
                {
                    TreeNode *currParent;

                    while (curr->left)
                    {
                        currParent = curr;
                        curr = curr->left;
                    }

                    std::swap(parent->val, curr->val);

                    if (curr->right)
                    {
                        currParent->left = curr->right;
                    }
                    else
                    {
                        currParent->left = nullptr;
                    }
                }
            }
            else if (curr->left || curr->right)
            {
                if (curr->left)
                {
                    if (curr == root)
                        root = curr->left;
                    else
                    {
                        if (parent->left == curr)
                            parent->left = curr->left;
                        else
                            parent->right = curr->left;
                    }
                }
                else
                {
                    parent = curr;
                    curr = curr->right;

                    if (!curr->left)
                    {
                        TreeNode *currRight = curr->right;
                        std::swap(parent->val, curr->val);
                        parent->right = currRight;
                    }
                    else
                    {
                        TreeNode *currParent;

                        while (curr->left)
                        {
                            currParent = curr;
                            curr = curr->left;
                        }

                        std::swap(parent->val, curr->val);

                        if (curr->right)
                        {
                            currParent->left = curr->right;
                        }
                        else
                        {
                            currParent->left = nullptr;
                        }
                    }
                }
            }
            else
            {
                if (parent->left == curr)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
        }

        return root;
    }
};

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(5);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(6);
    TreeNode *n3 = new TreeNode(1);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(7);
    TreeNode *n6 = new TreeNode(3);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->right = n5;

    n4->left = n6;

    Solution *s = new Solution();
    std::cout << s->deleteNode(root, 7) << std::endl;
}