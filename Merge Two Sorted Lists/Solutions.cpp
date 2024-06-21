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
    ListNode *head = new ListNode(0);
    ListNode *res = head;

    while (list1 && list2)
    {
        if (list1->val > list2->val)
        {
            head->next = list2;
            list2 = list2->next;
        }
        else
        {
            head->next = list1;
            list1 = list1->next;
        }

        head = head->next;
    }

    head->next = list1 ? list1 : list2;

    return res->next;
}

ListNode *mergeTwoLists_Recursion(ListNode *list1, ListNode *list2)
{
    if (!list1 || !list2)
        return list1 ? list1 : list2;

    if (list1->val > list2->val)
        std::swap(list1, list2);

    list1->next = mergeTwoLists_Recursion(list1->next, list2);

    return list1;
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

    // ListNode *node = mergeTwoLists_Recursion(list1, list2);
    // while (node)
    // {
    //     std::cout << node->val << " ";
    //     node = node->next;
    // }

    ListNode *node_ = mergeTwoLists(list1, list2);
    while (node_)
    {
        std::cout << node_->val << " ";
        node_ = node_->next;
    }
}