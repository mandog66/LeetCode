#ifndef MINHEAP_H
#define MINHEAP_H
#include <vector>
#include <iostream>

class minHeap
{
public:
    minHeap();
    void add(int num);
    void pop();
    int peek();

    friend std::ostream &operator<<(std::ostream &, const minHeap &);

private:
    std::vector<int> min_h;
};
#endif