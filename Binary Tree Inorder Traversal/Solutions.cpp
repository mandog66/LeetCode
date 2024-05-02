#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using std::stack;
using std::unordered_set;
using std::vector;

std::ostream &operator<<(std::ostream &out, const vector<int> &nums)
{
    out << "[";
    for (int i = 0; i < nums.size(); i++)
    {
        out << (i != 0 ? ", " : "") << nums[i];
    }
    out << "]" << std::endl;

    return out;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* ********************* Morris traversal ********************* */
// 參考資料 : https://blog.taiwolskit.com/algorithm-morris-traversal

vector<int> inorderTraversal_Morris(TreeNode *root)
{
    vector<int> res;

    while (root)
    {
        if (root->left)
        {
            TreeNode *prev = root->left;

            while (prev->right && prev->right != root)
            {
                prev = prev->right;
            }

            if (!prev->right)
            {
                prev->right = root;
                root = root->left;
            }
            else
            {
                prev->right = nullptr;
                res.push_back(root->val);
                root = root->right;
            }
        }
        else
        {
            res.push_back(root->val);
            root = root->right;
        }
    }

    return res;
}

/* ********************* Morris traversal ********************* */

/* ********************* Iterative solution using stack ********************* */

vector<int> inorderTraversal_stack(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> todo;

    while (root || !todo.empty())
    {
        while (root)
        {
            todo.push(root);
            root = root->left;
        }

        root = todo.top();
        todo.pop();
        res.push_back(root->val);
        root = root->right;
    }

    return res;
}

/* ********************* Iterative solution using stack ********************* */

// Definition for a binary tree node.
int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n8 = new TreeNode(8);
    TreeNode *n9 = new TreeNode(9);

    root->left = n2;
    root->right = n3;
    n2->left = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n4->right = n8;
    n5->left = n9;

    std::cout << inorderTraversal_Morris(root) << std::endl; // [4, 8, 2, 9, 5, 1, 6, 3, 7]
    std::cout << inorderTraversal_stack(root) << std::endl;  // [4, 8, 2, 9, 5, 1, 6, 3, 7]
}
