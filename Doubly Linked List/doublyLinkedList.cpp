#include "doublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    size = 0;
}

int DoublyLinkedList::get(int index)
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

void DoublyLinkedList::addAtHead(int val)
{
    addAtIndex(0, val);
}

void DoublyLinkedList::addAtTail(int val)
{
    addAtIndex(size, val);
}

void DoublyLinkedList::addAtIndex(int index, int val)
{
    if (index > size || index < 0)
    {
        return;
    }

    Node *currentNode = head;
    Node *newNode = new Node(val);

    if (index == 0)
    {
        newNode->next = currentNode;
        if (currentNode)
            currentNode->prev = newNode;
        head = newNode;
    }
    else if (index == size)
    {
        for (int i = 0; i < index - 1; i++)
        {
            currentNode = currentNode->next;
        }

        newNode->prev = currentNode;
        currentNode->next = newNode;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            currentNode = currentNode->next;
        }

        newNode->prev = currentNode->prev;
        newNode->next = currentNode;
        currentNode->prev->next = newNode;
        currentNode->prev = newNode;
    }

    size++;
}

void DoublyLinkedList::deleteAtIndex(int index)
{
    if (index >= size || index < 0)
    {
        return;
    }

    if (index == 0)
    {
        if (!head->next)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *tempNode = head;
            head = head->next;
            head->prev = nullptr;
            delete tempNode;
        }
    }
    else if (index == size - 1)
    {
        Node *currentNode = head;
        for (int i = 0; i < index - 1; i++)
        {
            currentNode = currentNode->next;
        }

        delete currentNode->next;
        currentNode->next = nullptr;
    }
    else
    {
        Node *currentNode = head;
        for (int i = 0; i < index; i++)
        {
            currentNode = currentNode->next;
        }

        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
        delete currentNode;
    }

    size--;
}

void DoublyLinkedList::show()
{
    Node *currentNode = head;
    for (int i = 0; i < size; i++)
    {
        cout << currentNode->value << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}
