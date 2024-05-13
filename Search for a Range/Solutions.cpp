#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

std::ostream &operator<<(std::ostream &os, const vector<int> &nums)
{
    os << "[";

    for (int i = 0; i < nums.size(); i++)
    {
        os << nums[i] << (i != nums.size() - 1 ? ", " : "");
    }

    os << "]";

    return os;
}

// watch solution video : https://www.youtube.com/watch?v=4sQL7R5ySUU
int binarySearch(vector<int> &nums, int target, bool leftBias)
{
    int l = 0;
    int r = nums.size() - 1;
    int res = -1; // target index

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] > target)
            // search in left
            r = m - 1;
        else if (nums[m] < target)
            // search in right
            l = m + 1;
        else
        {
            // mid is equal to target
            res = m; // target index

            if (leftBias)
                // we want to search the target which is most left in nums
                r = m - 1;
            else
                // we want to search the target which is most right in nums
                l = m + 1;
        }
    }

    return res;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    // search twice
    // for find the most left and right target index
    int l = binarySearch(nums, target, true);
    int r = binarySearch(nums, target, false);

    return {l, r};
}

int main(int argc, char *argv[])
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    std::cout << searchRange(nums, target) << std::endl; // [3, 4]

    nums = {5, 7, 7, 8, 8, 10};
    target = 6;
    std::cout << searchRange(nums, target) << std::endl; // [-1, -1]

    nums = {3, 3, 3};
    target = 3;
    std::cout << searchRange(nums, target) << std::endl; // [0, 2]

    nums = {1, 3};
    target = 1;
    std::cout << searchRange(nums, target) << std::endl; // [0, 0]
}