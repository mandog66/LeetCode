#ifndef MYLINKLIST_H
#define MYLINKLIST_H
#include <iostream>
using namespace std;

class MyLinkedList
{
public:
    MyLinkedList();
    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
    auto getHead();
    int getSize();
    void showList();

private:
    struct Node
    {
        int value;
        Node *next;

        // 初始化參數
        // 當然也可以寫成建構子的樣子
        Node(int val) : value(val), next(nullptr) {}
    };

    Node *head;
    int size;
};

#endif