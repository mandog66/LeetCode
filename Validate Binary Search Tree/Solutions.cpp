#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool valid(TreeNode *node, long left, long right)
{
    // 當 node 沒有左子樹和沒有右子樹
    if (!node)
        return true;

    // 必須符合二元搜尋樹的規則(不能超過邊界)
    if (!(node->val > left && node->val < right))
        return false;

    // valid(下一個子節點, 左邊界, 右邊界)
    // 往左子節點走，左邊界不變，右邊界變成父節點(左子節點必須小於父節點)
    // 往右子節點走，右邊界不變，左邊界變成父節點(右子節點必須大於父節點)
    return valid(node->left, left, node->val) && valid(node->right, node->val, right);
}

bool isValidBST(TreeNode *root)
{
    return valid(root, LONG_MIN, LONG_MAX);
}

int main(int argc, char *argv[])
{
    TreeNode *root1 = new TreeNode(2);
    TreeNode *n12 = new TreeNode(1);
    TreeNode *n13 = new TreeNode(3);
    root1->left = n12;
    root1->right = n13;
    std::cout << (isValidBST(root1) ? "True" : "False") << std::endl; // True

    TreeNode *root2 = new TreeNode(5);
    TreeNode *n22 = new TreeNode(4);
    TreeNode *n23 = new TreeNode(6);
    TreeNode *n26 = new TreeNode(3);
    TreeNode *n27 = new TreeNode(7);
    root2->left = n22;
    root2->right = n23;
    n23->left = n26;
    n23->right = n27;
    std::cout << (isValidBST(root2) ? "True" : "False") << std::endl; // False

    TreeNode *root3 = new TreeNode(1);
    TreeNode *n32 = new TreeNode(1);
    root3->left = n32;
    std::cout << (isValidBST(root3) ? "True" : "False") << std::endl; // False

    TreeNode *root4 = new TreeNode(3);
    TreeNode *n42 = new TreeNode(1);
    TreeNode *n43 = new TreeNode(5);
    TreeNode *n44 = new TreeNode(0);
    TreeNode *n45 = new TreeNode(2);
    TreeNode *n46 = new TreeNode(4);
    TreeNode *n47 = new TreeNode(6);
    root4->left = n42;
    root4->right = n43;
    n42->left = n44;
    n42->right = n45;
    n43->left = n46;
    n43->right = n47;
    std::cout << (isValidBST(root4) ? "True" : "False") << std::endl; // True

    TreeNode *root5 = new TreeNode(32);
    TreeNode *n52 = new TreeNode(26);
    TreeNode *n53 = new TreeNode(47);
    TreeNode *n54 = new TreeNode(19);
    TreeNode *n57 = new TreeNode(56);
    TreeNode *n59 = new TreeNode(27);
    root5->left = n52;
    root5->right = n53;
    n52->left = n54;
    n53->right = n57;
    n54->right = n59;
    std::cout << (isValidBST(root5) ? "True" : "False") << std::endl; // False
}