#include <iostream>
#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

int findDuplicate(vector<int> &nums)
{
    unordered_set<int> set;
    for (int n : nums)
    {
        if (set.count(n))
            return n;

        set.insert(n);
    }

    return -1;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 3, 4, 2, 2};
    std::cout << findDuplicate(nums) << std::endl; // 2

    nums = {3, 1, 3, 4, 2};
    std::cout << findDuplicate(nums) << std::endl; // 3

    nums = {3, 3, 3, 3, 3};
    std::cout << findDuplicate(nums) << std::endl; // 3
}