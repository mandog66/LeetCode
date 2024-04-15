#include "CircularQueue.h"
#include <iostream>

int main()
{
    CircularQueue *q = new CircularQueue(3);
    std::cout << q->enQueue(1) << std::endl;
    std::cout << q->enQueue(2) << std::endl;
    std::cout << q->enQueue(3) << std::endl;
    std::cout << q->enQueue(4) << std::endl;
    std::cout << q->Rear() << std::endl;
    std::cout << q->isFull() << std::endl;
    std::cout << q->deQueue() << std::endl;
    std::cout << q->enQueue(4) << std::endl;
    std::cout << q->Rear() << std::endl;
}