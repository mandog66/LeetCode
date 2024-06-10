#include <iostream>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    /*
        currParent : 根節點，目的是找到下一個子節點

        baseChild : 當子節點都完成後(一層 Level-Order 結束)，要進入下一個根節點的位置(下一層 Level-Order 的起點)

        currChild : 目前的子節點

        nextChild : 下一個子節點
    */
    Node *currParent = root, *baseChild, *currChild, *nextChild;

    // 剛好可以符合根節點為空的狀況
    while (currParent)
    {
        // 跳過沒有子節點的根節點，可能發生在沒有左子樹但有右子樹的情況
        while (currParent->next && !currParent->left && !currParent->right)
            currParent = currParent->next;
        // 設置 Level-Order 的起點
        currChild = baseChild = currParent->left ? currParent->left : currParent->right;
        while (currChild)
        {
            // 右節點是左節點的下一個節點，如果目前的節點等於右節點，表示是根節點的最後一個子節點
            if (currParent->right && currChild != currParent->right)
                nextChild = currParent->right;
            else
            {
                // 找到下一個節點的根節點，可能為空
                currParent = currParent->next;
                // 下一個節點可能跨過多個根節點
                while (currParent && !currParent->left && !currParent->right)
                    currParent = currParent->next;
                // 設置下一個節點，可能為空
                nextChild = currParent ? currParent->left ? currParent->left : currParent->right : currParent;
            }
            currChild->next = nextChild;
            currChild = nextChild;
        }
        // 進入下一層 Level-Order
        currParent = baseChild;
    }
    return root;
}

int main(int argc, char *argv[])
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;

    connect(n1);
}