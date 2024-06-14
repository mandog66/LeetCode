#include <iostream>
#include <vector>

using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *newHead = head;
    while (newHead && newHead->next)
    {
        std::swap(newHead->val, newHead->next->val);
        newHead = newHead->next->next;
    }

    return head;
}

int main(int argc, char *argv[])
{
    ListNode *head = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;

    head = swapPairs(head);
    std::cout << head->val << std::endl;
}