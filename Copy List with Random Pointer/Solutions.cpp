#include <iostream>
#include <map>

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
    map<CNode *, CNode *> m;
    CNode *cur = head;

    while (cur)
    {
        m[cur] = new CNode(cur->val);
        cur = cur->next;
    }

    cur = head;
    while (cur)
    {
        /*
            map[原鏈結] = 新鏈結
        */
        m[cur]->next = m[cur->next];
        m[cur]->random = m[cur->random];
        cur = cur->next;
    }

    return m[head];
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
