#include <vector>
#include <iostream>
#include <stack>

using std::stack;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Frame
{
    TreeNode *node;
    Frame *parent;
    vector<TreeNode *> subs;
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    /*
        answer 這裡不用 Frame * 的原因是要創建一個物件而不是指標，如果是指標 answer 就不會被初始化，
        只會是指到一個位址，那先創建一個物件會是先初始化再利用 & 轉成物件位址。
    */
    Frame answer;
    stack<Frame> stack;
    stack.push({root, &answer});

    while (stack.size())
    {
        /*
            基本上就是子節點互相比較後結果存在 parent。

            一層一層往根節點移動，先從葉子節點當作根節點比較左右子樹(當然左右子樹都為空)，結果傳回葉子節點，
            依此類推由小到大一層一層傳會結果，最後就會到根節點比較左右子樹的結果，傳回答案。
        */
        Frame *top = &stack.top(), *parent = top->parent;
        TreeNode *node = top->node;

        if (!node || node == p || node == q)
        {
            parent->subs.push_back(node);
            stack.pop();
        }
        else if (top->subs.empty())
        {
            // 表示節點還沒被拜訪過
            stack.push({node->right, top});
            stack.push({node->left, top});
        }
        else
        {
            // 節點的左右子樹都已被拜訪
            TreeNode *left = top->subs[0], *right = top->subs[1];
            parent->subs.push_back(!left ? right : (!right ? left : node));
            stack.pop();
        }
    }

    return answer.subs[0];
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