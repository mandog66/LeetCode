#include "MyLinkList.h"

MyLinkedList::MyLinkedList()
{
    head = nullptr;
    size = 0;
}

int MyLinkedList::get(int index)
{
    if (index >= size || index < 0)
    {
        return -1;
    }
    else
    {
        Node *currentNode = head;

        for (int i = 0; i < index; i++)
        {
            currentNode = currentNode->next;
        }

        return currentNode->value;
    }
}

void MyLinkedList::addAtHead(int val)
{
    addAtIndex(0, val);
}

void MyLinkedList::addAtTail(int val)
{
    addAtIndex(size, val);
}

void MyLinkedList::addAtIndex(int index, int val)
{
    if (index > size || index < 0)
    {
        return;
    }

    Node *currentNode = head;
    Node *newNode = new Node(val);

    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            currentNode = currentNode->next;
        }

        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }

    size++;
}

void MyLinkedList::deleteAtIndex(int index)
{
    if (index >= size || index < 0)
    {
        return;
    }
    else if (index == 0)
    {
        Node *tempNode = head;
        head = head->next;
        delete tempNode;
    }
    else
    {
        Node *currentNode = head;
        for (int i = 0; i < index - 1; i++)
        {
            currentNode = currentNode->next;
        }

        Node *nextNode = currentNode->next->next;
        delete currentNode->next;
        currentNode->next = nextNode;
    }

    size--;
}

void MyLinkedList::showList()
{
    Node *currentNode = head;
    for (int i = 0; i < size; i++)
    {
        cout << currentNode->value << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

auto MyLinkedList::getHead()
{
    return head;
}

int MyLinkedList::getSize()
{
    return size;
}

// int main()
// {
//     MyLinkedList *obj = new MyLinkedList();
//     obj->addAtHead(1);
//     obj->showList(); // 1

//     obj->addAtHead(2);
//     obj->showList(); // 2 1

//     obj->addAtTail(3);
//     obj->showList(); // 2 1 3

//     obj->addAtIndex(1, 2);
//     obj->showList(); // 2 2 1 3

//     obj->deleteAtIndex(1);
//     obj->showList(); // 2 1 3
// }
