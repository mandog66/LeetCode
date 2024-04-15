#include "CircularQueue.h"

// CircularQueue::CircularQueue(int k)
// {
//     head = nullptr;
//     tail = nullptr;
//     size = 0;
//     limitSize = k;
// }

// bool CircularQueue::enQueue(int value)
// {
//     node *newNode = new node(value);
//     if (!head)
//     {
//         head = newNode;
//         tail = newNode;
//         size++;
//         return true;
//     }

//     if (size < limitSize)
//     {
//         tail->left = newNode;
//         tail = newNode;
//         size++;
//         return true;
//     }
//     else
//         return false;
// }

// bool CircularQueue::deQueue()
// {
//     if (isEmpty())
//         return false;
//     else
//     {
//         node *temp = head;
//         head = head->left;
//         delete temp;
//         size--;
//         return true;
//     }
// }

// int CircularQueue::Front()
// {
//     if (isEmpty())
//         return -1;
//     else
//         return head->val;
// }

// int CircularQueue::Rear()
// {
//     if (isEmpty())
//         return -1;
//     else
//         return tail->val;
// }

// bool CircularQueue::isEmpty()
// {
//     if (size == 0)
//         return true;
//     else
//         return false;
// }

// bool CircularQueue::isFull()
// {
//     if (size == limitSize)
//         return true;
//     else
//         return false;
// }

CircularQueue::CircularQueue(int k)
{
    q.resize(k);
    head = -1;
    tail = -1;
    size = k;
}

bool CircularQueue::enQueue(int value)
{
    if (isFull())
        return false;

    if (isEmpty())
        head = 0;

    tail = (tail + 1) % size;
    q[tail] = value;
    return true;
}

bool CircularQueue::deQueue()
{
    if (isEmpty())
        return false;

    if (head == tail)
    {
        head = -1;
        tail = -1;
        return true;
    }

    head = (head + 1) % size;
    return true;
}

int CircularQueue::Front()
{
    if (isEmpty())
        return -1;
    else
        return q[head];
}

int CircularQueue::Rear()
{
    if (isEmpty())
        return -1;
    else
        return q[tail];
}

bool CircularQueue::isEmpty()
{
    return head == -1;
}

bool CircularQueue::isFull()
{
    return ((tail + 1) % size) == head;
}
