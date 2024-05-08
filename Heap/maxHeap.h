#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
#include <iostream>

class maxHeap
{
public:
    maxHeap();
    void add(int num);
    void pop();
    int peek();
    void print();

    friend std::ostream &operator<<(std::ostream &out, const maxHeap &maxHeap);

private:
    std::vector<int> max_h;
};
#endif