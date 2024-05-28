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

bool isSymmetric(TreeNode *root)
{
    if (!root->left && !root->right)
        return true;

    /************************* recursive *************************/
    // 想不到，看解答
    /************************* recursive *************************/

    /************************* iteration *************************/
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> compare;

        for (int i = 0; i < n; i++)
        {
            TreeNode *cur = q.front();
            q.pop();

            if (cur->left)
            {
                q.push(cur->left);
                compare.push_back(cur->left->val);
            }
            else
            {
                compare.push_back(-101);
            }

            if (cur->right)
            {
                q.push(cur->right);
                compare.push_back(cur->right->val);
            }
            else
            {
                compare.push_back(-101);
            }
        }

        int i = 0, j = compare.size() - 1;
        while (i < j)
        {
            if (compare[i] != compare[j])
                return false;

            i++;
            j--;
        }
    }

    return true;
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