#include <iostream>

#include "doublyLinkedList.h"

using namespace std;

int main()
{
    DoublyLinkedList *obj = new DoublyLinkedList();
    // obj->addAtHead(0);
    // obj->addAtIndex(1, 4);
    // obj->addAtTail(8);
    // obj->addAtHead(5);
    // obj->addAtIndex(4, 3);
    // obj->addAtTail(0);
    // obj->addAtTail(5);
    // obj->addAtIndex(6, 3);
    // obj->show();
    // obj->deleteAtIndex(7);
    // obj->show();
    // obj->deleteAtIndex(5);
    // obj->show();
    // obj->addAtTail(4);
    // obj->show();

    // obj->addAtHead(3);
    // obj->addAtHead(2);
    // obj->addAtHead(1);
    obj->addAtTail(1);
    obj->addAtTail(2);
    obj->addAtTail(3);
    // obj->addAtIndex(2, 4);
    obj->deleteAtIndex(1);
    obj->show();
}