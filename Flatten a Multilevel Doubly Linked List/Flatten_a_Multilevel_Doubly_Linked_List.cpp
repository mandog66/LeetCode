#include <iostream>
#include <stack>

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

Node *flatten(Node *head)
{
    if (!head)
        return nullptr;

    stack<Node *> nextStack; // 下一個節點的堆疊
    Node *res = head;        //  結果
    Node *curRes = head;     // 新增節點到結果
    Node *curList = head;    // 鏈結目前的位置
    Node *childNode = head->child;

    while (true)
    {
        // have child node
        while (childNode)
        {
            if (curList->next)
            {
                nextStack.push(curList->next);
            }
            curList->child = nullptr;
            curRes->next = childNode;
            childNode->prev = curRes;
            curRes = curRes->next;
            curList = childNode;
            childNode = childNode->child;
            curRes->child = nullptr;
        }

        // have next node of current node
        if (curList->next)
        {
            curList = curList->next;
            curRes->next = curList;
            curList->prev = curRes;
            curRes = curList;
            childNode = curList->child;
            curRes->child = nullptr;
        }
        // back the child node
        else if (!nextStack.empty())
        {
            curList = nextStack.top();
            nextStack.pop();
            curRes->next = curList;
            curList->prev = curRes;
            curRes = curRes->next;
            curRes->child = nullptr;
        }
        else
        {
            return res;
        }
    }

    return res;
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
