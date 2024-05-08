#include "maxHeap.h"

std::ostream &operator<<(std::ostream &out, const maxHeap &maxHeap)
{
    const int n = maxHeap.max_h.size();

    out << "[";

    for (int j = 0; j < n; j++)
    {
        out << (j != 0 ? ", " : "") << maxHeap.max_h[j];
    }

    out << "]";

    return out;
}

/* Max Heap */
maxHeap::maxHeap()
{
    max_h = std::vector<int>();
}

void maxHeap::add(int num)
{
    max_h.push_back(num);

    int index = max_h.size() - 1;
    int parent = (index + 1) / 2 - 1;

    while (index > 0 && max_h[index] > max_h[parent])
    {
        int temp = max_h[index];
        max_h[index] = max_h[parent];
        max_h[parent] = temp;
        index = parent;
        parent = (index + 1) / 2 - 1;
    }
}

void maxHeap::pop()
{
    if (max_h.size() <= 0)
        std::cout << "Empty Heap" << std::endl;
    else
    {
        max_h[0] = max_h[max_h.size() - 1];
        max_h.pop_back();

        int index = 0;

        while (index <= max_h.size() / 2 - 1)
        {
            int left = (index + 1) * 2 - 1;
            int right = (index + 1) * 2;

            if (max_h[index] < max_h[left] || max_h[index] < max_h[right])
            {
                if (max_h[left] > max_h[right])
                {
                    int temp = max_h[index];
                    max_h[index] = max_h[left];
                    max_h[left] = temp;
                    index = left;
                }
                else
                {
                    int temp = max_h[index];
                    max_h[index] = max_h[right];
                    max_h[right] = temp;
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

int maxHeap::peek()
{
    if (max_h.size() <= 0)
    {
        std::cout << "Empty Heap" << std::endl;
        return 0;
    }
    return max_h[0];
}

void maxHeap::print()
{
    std::cout << this << std::endl;
    return;
}
/* Max Heap */