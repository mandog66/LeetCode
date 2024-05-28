#include <iostream>
#include <vector>
#include <queue>

using std::queue;
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
bool helper(TreeNode *left, TreeNode *right)
{
    if (!left && !right)
        return true;

    if (!left || !right)
        return false;

    return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
}

bool isSymmetric(TreeNode *root)
{
    /************************* recursive *************************/
    if (!root)
        return true;

    return helper(root->left, root->right);
    /************************* recursive *************************/

    /************************* iteration *************************/
    // queue<TreeNode *> q;
    // q.push(root->left);
    // q.push(root->right);

    // while (!q.empty())
    // {
    //     TreeNode *left = q.front();
    //     q.pop();
    //     TreeNode *right = q.front();
    //     q.pop();

    //     if (!left && !right)
    //         continue;

    //     if (!left || !right)
    //         return false;

    //     if (left->val != right->val)
    //         return false;

    //     q.push(left->left);
    //     q.push(right->right);
    //     q.push(left->right);
    //     q.push(right->left);
    // }

    // return true;
    /************************* iteration *************************/
}

int main(int argc, char *argv[])
{
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(2);
    TreeNode *n4 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(3);

    n1->left = n2;
    n1->right = n3;
    n2->right = n4;
    n3->right = n5;

    std::cout << (isSymmetric(n1) ? "True" : "False") << std::endl;
}