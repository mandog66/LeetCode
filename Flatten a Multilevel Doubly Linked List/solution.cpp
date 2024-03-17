#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;
    Node *child;
    Node() : val(0), next(nullptr), prev(nullptr), child(nullptr) {}
    Node(int x) : val(x), next(nullptr), prev(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
};

Node *flattenHelper(Node *head)
{
    /*
        tail : 連接子鏈結最後一個節點和原鏈結的下一個節點
        node : 目前鏈結節點的位置
        child : 子鏈結透過遞迴迭代子鏈結所有節點
        next : 與 tail 連接的節點或是單純的下一個節點

        child 是 reference 目的是讓 child 在需要重新"鏈結對象(nullptr)"時譨能夠被參考

        這裡檢查節點沒有重複鏈結，因為是指標，只要確定沒有子節點，就可以直接檢查下一個節點，鏈結本來就是連接好的。
        如果有子節點需要更改鏈結對象時，才會去執行其他操作。
    */
    auto tail = head;
    for (auto node = head; node;)
    {
        auto next = node->next;
        auto &child = node->child;
        if (child)
        {
            tail = flattenHelper(child);
            node->next = child;
            child->prev = node;
            tail->next = next;
            if (next)
                next->prev = tail;
            child = nullptr;
        }
        else
        {
            tail = node;
        }
        node = next;
    }
    return tail;
}

Node *flatten(Node *head)
{
    flattenHelper(head);
    return head;
}

template <typename T>
void show(T *head)
{
    T *tmp1 = head;
    while (tmp1->next)
    {
        cout << tmp1->val << " ";
        tmp1 = tmp1->next;
    }
    cout << tmp1->val << " ";
    cout << endl;
}

int main()
{
    // Node *n1 = new Node(1);
    // Node *n2 = new Node(2);
    // Node *n3 = new Node(3);
    // Node *n4 = new Node(4);
    // Node *n5 = new Node(5);
    // Node *n6 = new Node(6);
    // Node *n7 = new Node(7);
    // Node *n8 = new Node(8);
    // Node *n9 = new Node(9);
    // Node *n10 = new Node(10);
    // Node *n11 = new Node(11);
    // Node *n12 = new Node(12);

    // n1->next = n2;

    // n2->prev = n1;
    // n2->next = n3;

    // n3->prev = n2;
    // n3->next = n4;
    // n3->child = n7;

    // n4->prev = n3;
    // n4->next = n5;

    // n5->prev = n4;
    // n5->next = n6;

    // n6->prev = n5;
    // n6->next = nullptr;

    // n7->next = n8;

    // n8->prev = n7;
    // n8->next = n9;
    // n8->child = n11;

    // n9->prev = n8;
    // n9->next = n10;

    // n10->prev = n9;
    // n10->next = nullptr;

    // n11->next = n12;

    // n12->prev = n11;
    // n12->next = nullptr;

    // Node *n1 = new Node(1);
    // Node *n2 = new Node(2);
    // Node *n3 = new Node(3);

    // n1->next = n2;
    // n2->prev = n1;
    // n1->child = n3;

    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);

    n1->child = n2;
    n2->child = n3;

    Node *res = flatten(n1);
    show(res);
}
