#include "minHeap.h"

std::ostream &operator<<(std::ostream &out, const minHeap &m)
{
    const int n = m.min_h.size();

    out << "[";

    for (int j = 0; j < n; j++)
    {
        out << (j != 0 ? ", " : "") << m.min_h[j];
    }

    out << "]";

    return out;
}

/* Min Heap */
minHeap::minHeap()
{
    min_h = std::vector<int>();
}

void minHeap::add(int num)
{
    min_h.push_back(num);

    int index = min_h.size() - 1;
    int parent = (index + 1) / 2 - 1;

    while (index > 0 && min_h[index] < min_h[parent])
    {
        int temp = min_h[index];
        min_h[index] = min_h[parent];
        min_h[parent] = temp;
        index = parent;
        parent = (index + 1) / 2 - 1;
    }
}

void minHeap::pop()
{
    if (min_h.size() <= 0)
        std::cout << "Empty Heap" << std::endl;
    else
    {
        min_h[0] = min_h[min_h.size() - 1];
        min_h.pop_back();

        int index = 0;

        while (min_h.size() > 1 && index <= min_h.size() / 2 - 1)
        {
            int left = (index + 1) * 2 - 1;
            int right = (index + 1) * 2;

            if (min_h[index] > min_h[left] || min_h[index] > min_h[right])
            {
                if (min_h[left] < min_h[right])
                {
                    int temp = min_h[index];
                    min_h[index] = min_h[left];
                    min_h[left] = temp;
                    index = left;
                }
                else
                {
                    int temp = min_h[index];
                    min_h[index] = min_h[right];
                    min_h[right] = temp;
                    index = right;
                }
            }
            else
            {
                break;
            }
        }
    }
}

int minHeap::peek()
{
    if (min_h.size() <= 0)
    {
        std::cout << "Empty Heap" << std::endl;
        return 0;
    }
    else
    {
        return min_h[0];
    }
}

/* Min Heap */