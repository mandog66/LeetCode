#include <iostream>
#include <queue>

using std::queue;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool is_valid(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;

    if (!p || !q)
        return false;

    if (p->val != q->val)
        return false;

    return true;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    /* Iteration */
    queue<std::pair<TreeNode *, TreeNode *>> todo;
    todo.push(std::make_pair(p, q));

    while (!todo.empty())
    {
        std::pair<TreeNode *, TreeNode *> cur = todo.front();
        todo.pop();
        TreeNode *l = cur.first;
        TreeNode *r = cur.second;

        if (!is_valid(l, r))
            return false;

        if (l)
        {
            todo.push(std::make_pair(l->left, r->left));
            todo.push(std::make_pair(l->right, r->right));
        }
    }
    return true;

    /* Recursion */
    // if (!p && !q)
    //     return true;

    // if (!p || !q)
    //     return false;

    // if (p->val != q->val)
    //     return false;

    // return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char *argv[])
{
    TreeNode *p = new TreeNode(1);
    TreeNode *pl1 = new TreeNode(2);
    TreeNode *pr1 = new TreeNode(3);
    p->left = pl1;
    p->right = pr1;

    TreeNode *q = new TreeNode(1);
    TreeNode *ql1 = new TreeNode(2);
    TreeNode *qr1 = new TreeNode(3);
    q->left = ql1;
    q->right = qr1;

    std::cout << (isSameTree(p, q) ? "True" : "False") << std::endl;

    TreeNode *p_ = new TreeNode(1);
    TreeNode *p_l1 = new TreeNode(3);
    TreeNode *p_r1 = new TreeNode(2);
    p_->left = p_l1;
    p_->right = p_r1;

    TreeNode *q_ = new TreeNode(1);
    TreeNode *q_l1 = new TreeNode(2);
    TreeNode *q_r1 = new TreeNode(3);
    q_->left = q_l1;
    q_->right = q_r1;

    std::cout << (isSameTree(p_, q_) ? "True" : "False") << std::endl;
}