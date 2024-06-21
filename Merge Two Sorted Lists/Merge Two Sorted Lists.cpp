#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1 && !list2)
        return nullptr;
    else if (!list1)
        return list2;
    else if (!list2)
        return list1;

    ListNode *idx1 = list1;
    ListNode *idx2 = list2;
    ListNode *next, *cur;

    if (idx1->val >= idx2->val)
    {
        next = mergeTwoLists(idx1, idx2->next);
        cur = idx2;
    }
    else
    {
        next = mergeTwoLists(list1->next, idx2);
        cur = idx1;
    }

    cur->next = next;

    return cur;
}

int main(int argc, char *argv[])
{
    ListNode *list1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n4 = new ListNode(4);
    list1->next = n2;
    n2->next = n4;

    ListNode *list2 = new ListNode(1);
    ListNode *n3 = new ListNode(3);
    ListNode *n4_ = new ListNode(4);
    list2->next = n3;
    n3->next = n4_;

    ListNode *node = mergeTwoLists(list1, list2);
    while (node)
    {
        std::cout << node->val << " ";
        node = node->next;
    }
}