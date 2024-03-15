#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
    void show();

private:
    struct Node
    {
        int value;
        Node *next;
        Node *prev;

        Node(int val)
        {
            value = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node *head;
    int size;
};
#endif