#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <vector>

// class CircularQueue
// {
// public:
//     CircularQueue(int k);
//     bool enQueue(int value);
//     bool deQueue();
//     int Front();
//     int Rear();
//     bool isEmpty();
//     bool isFull();

// private:
//     struct node
//     {
//         node *left;
//         int val;

//         node() : left(nullptr), val(-1){};
//         node(int val) : left(nullptr), val(val){};
//     };

//     node *head;
//     node *tail;
//     int size;
//     int limitSize;
// };

class CircularQueue
{
public:
    CircularQueue(int k);
    bool enQueue(int value);
    bool deQueue();
    int Front();
    int Rear();
    bool isEmpty();
    bool isFull();

private:
    std::vector<int> q;
    int head;
    int tail;
    int size;
};
#endif