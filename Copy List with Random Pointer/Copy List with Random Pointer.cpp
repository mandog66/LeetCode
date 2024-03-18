#include <iostream>

using namespace std;

struct CNode
{
    int val;
    CNode *next;
    CNode *random;

    CNode(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

CNode *copyRandomList(CNode *head)
{
    if (!head)
        return nullptr;

    if (head->next == nullptr)
    {
        CNode *res = new CNode(head->val);
        if (head->random == head)
            res->random = res;

        return res;
    }

    CNode *newHead = new CNode(head->val);
    CNode *res = newHead;

    for (auto node = head->next; node;)
    {
        CNode *newNode = new CNode(node->val);
        newHead->next = newNode;
        node = node->next;
        newHead = newHead->next;
    }

    CNode *resNode = res;
    for (auto node = head; node;)
    {
        CNode *r = node->random;
        if (r == nullptr)
        {
            resNode->random = nullptr;
        }
        else
        {
            int idx = 0;
            for (auto _node = head; _node != r;)
            {
                _node = _node->next;
                idx++;
            }

            CNode *cur = res;
            for (int i = 0; i < idx; i++)
            {
                cur = cur->next;
            }

            resNode->random = cur;
        }

        node = node->next;
        resNode = resNode->next;
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
    CNode *n7 = new CNode(7);
    CNode *n13 = new CNode(13);
    CNode *n11 = new CNode(11);
    CNode *n10 = new CNode(10);
    CNode *n1 = new CNode(1);

    n7->next = n13;
    n7->random = n1->next;

    n13->next = n11;
    n13->random = n7;

    n11->next = n10;
    n11->random = n1;

    n10->next = n1;
    n10->random = n11;

    n1->random = n7;

    show(n7);

    CNode *res = copyRandomList(n7);
    show(res);
    cout << endl;
}
