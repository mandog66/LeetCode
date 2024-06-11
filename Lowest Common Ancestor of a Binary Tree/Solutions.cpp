#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    /*
        利用 "子樹" 來解決問題。

        如果兩節點(p and q)在同一個子樹，結果就是LCA。
        如果只有一個節點(p or q)在一個子樹，結果會是那一個節點(p or q)。
        如果兩個子樹都不在，結果會是 nullptr。

        依照下面的樹解釋 :
            p = 5
            q = 4

            兩個節點在左子樹，右子樹為空，所以 LCA 是 左子樹的節點。

            或是

            p = 5
            q = 0

            p 在左子樹而 q 在右子樹，因為兩點都存在所以結果是根節點。
    */
    if (!root || root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    return (!left) ? right : ((!right) ? left : root);
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