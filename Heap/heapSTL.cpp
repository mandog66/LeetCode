#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using std::multiset;
using std::nth_element;
using std::partial_sort;
using std::priority_queue;
using std::vector;

std::ostream &operator<<(std::ostream &out, const vector<int> &nums)
{
    const int n = nums.size();

    out << "[";

    for (int j = 0; j < n; j++)
    {
        out << (j != 0 ? ", " : "") << nums[j];
    }

    out << "]";

    return out;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    // partial sorting 部分排序方法
    // 會將前 k 個元素從小排到大，剩餘元素則沒有排序限制。
    // 可以在第三個參數放比較方式(預設是元素小的放前面)。
    // https://cplusplus.com/reference/algorithm/nth_element/
    nth_element(nums.begin(), nums.begin() + k, nums.end());
    std::cout << nums << std::endl; // [2, 1, 3, 4, 6, 5]

    nums = {3, 2, 1, 5, 6, 4};
    k = 2;

    // 第三個參數放 大於 比較方式，讓大的元素排到前面。
    nth_element(nums.begin(), nums.begin() + k, nums.end(), std::greater<int>());
    std::cout << nums << std::endl; // [6, 5, 4, 1, 2, 3]

    // partial sorting 部分排序方法
    // 會依照 middle參數(第二個參數) 的元素大小重新排序，middle參數前的元素是最小的，其他元素的排序沒有限制。
    // 可以在第三個參數放比較方式(預設是元素小的放前面)。
    // https://cplusplus.com/reference/algorithm/partial_sort/
    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    std::partial_sort(nums.begin(), nums.begin() + k, nums.end());
    std::cout << nums << std::endl; // [1, 2, 3, 5, 6, 4]

    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    // 第三個參數放 大於 比較方式，讓大的元素排到前面。
    std::partial_sort(nums.begin(), nums.begin() + k, nums.end(), std::greater<int>());
    std::cout << nums << std::endl; // [6, 5, 1, 2, 3, 4]

    // STL Heap using priority_queue
    // 這是一種容器，會進行 Heap 的排序。
    // 第三個參數預設是 less<int> 代表 較小的元素排後面 -> Max Heap
    // https://cplusplus.com/reference/queue/priority_queue/
    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    priority_queue<int, vector<int>, std::less<int>> pq;
    for (int n : nums)
        pq.push(n);
    while (!pq.empty())
    {
        std::cout << " " << pq.top(); // 6 5 4 3 2 1
        pq.pop();
    }
    std::cout << std::endl;

    // 第三個參數是 greater<int> 代表 較大的元素排後面 -> Min Heap
    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    priority_queue<int, vector<int>, std::greater<int>> _pq;
    for (int n : nums)
        _pq.push(n);
    while (!_pq.empty())
    {
        std::cout << " " << _pq.top(); // 1 2 3 4 5 6
        _pq.pop();
    }
    std::cout << std::endl;

    // STL Heap using multiset
    // 這是一種容器，會進行 Heap 的排序。
    // https://cplusplus.com/reference/set/multiset/
    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    multiset<int> mset; // Min Heap
    for (int n : nums)
        mset.insert(n);
    for (auto it = mset.begin(); it != mset.end(); it++)
        std::cout << " " << *it; // 1 2 3 4 5 6
    std::cout << std::endl;

    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    multiset<int, std::greater<int>> _mset; // Max Heap
    for (int n : nums)
        _mset.insert(n);
    for (auto it = _mset.begin(); it != _mset.end(); it++)
        std::cout << " " << *it; // 6 5 4 3 2 1
    std::cout << std::endl;
}