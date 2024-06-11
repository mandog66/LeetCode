#include <iostream>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using std::queue;
using std::unordered_map;
using std::unordered_set;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
{
    queue<TreeNode *> todo;
    todo.push(root);
    parent[root] = nullptr;

    while (!todo.empty())
    {
        int n = todo.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *cur = todo.front();
            todo.pop();

            if (cur->left)
            {
                todo.push(cur->left);
                parent[cur->left] = cur;
            }

            if (cur->right)
            {
                todo.push(cur->right);
                parent[cur->right] = cur;
            }
        }
    }

    return;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    unordered_map<TreeNode *, TreeNode *> parent;
    traverse(root, parent);

    unordered_set<TreeNode *> pp;
    pp.insert(p);

    while (parent[p])
    {
        pp.insert(parent[p]);
        p = parent[p];
    }

    TreeNode *res = q;
    while (true)
    {
        if (pp.find(res) != pp.end())
            break;

        res = parent[res];
    }

    return res;
}

int main(int argc, char *argv[])
{
    TreeNode *n0 = new TreeNode(0);
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n8 = new TreeNode(8);

    n3->left = n5;
    n3->right = n1;

    n5->left = n6;
    n5->right = n2;

    n1->left = n0;
    n1->right = n8;

    n2->left = n7;
    n2->right = n4;

    std::cout << lowestCommonAncestor(n3, n5, n1)->val << std::endl;
    std::cout << lowestCommonAncestor(n3, n5, n4)->val << std::endl;
}