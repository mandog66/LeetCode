#include "MyLinkList.h"

int main()
{
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->showList(); // 1

    obj->addAtHead(2);
    obj->showList(); // 2 1

    obj->addAtTail(3);
    obj->showList(); // 2 1 3

    obj->addAtIndex(1, 2);
    obj->showList(); // 2 2 1 3

    obj->deleteAtIndex(1);
    obj->showList(); // 2 1 3
}
