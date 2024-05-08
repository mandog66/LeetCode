#include "minHeap.h"
#include "maxHeap.h"
#include <iostream>

int main()
{
    minHeap minheap;
    minheap.add(6);
    minheap.add(5);
    minheap.add(9);
    minheap.add(2);
    minheap.add(8);
    minheap.add(3);
    minheap.add(1);
    std::cout << minheap << std::endl; // [1, 5, 2, 6, 8, 9, 3]
    std::cout << minheap.peek() << std::endl;
    minheap.pop();
    std::cout << minheap << std::endl; // [2, 5, 3, 6, 8, 9]
    minheap.pop();
    std::cout << minheap << std::endl; // [3, 5, 9, 6, 8]

    maxHeap maxheap;
    maxheap.add(1);
    maxheap.add(3);
    maxheap.add(9);
    maxheap.add(4);
    maxheap.add(8);
    maxheap.add(2);
    maxheap.add(7);
    std::cout << maxheap << std::endl; // [9, 8, 7, 1, 4, 2, 3]
    std::cout << maxheap.peek() << std::endl;
    maxheap.pop();
    std::cout << maxheap << std::endl; // [8, 4, 7, 1, 3, 2]
    maxheap.pop();
    std::cout << maxheap << std::endl; // [7, 4, 2, 1, 3]
}