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

vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.empty())
        return {-1, -1};

    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (nums[l] == target && nums[r] == target)
            return {l, r};

        if (nums[m] >= nums[l] && nums[l] != target)
            l += 1;

        if (nums[m] <= nums[r] && nums[r] != target)
            r -= 1;
    }

    if (nums[l] != target && nums[r] != target)
        return {-1, -1};
    return {l, r};
}

int main(int argc, char *argv[])
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    std::cout << searchRange(nums, target) << std::endl;

    nums = {5, 7, 7, 8, 8, 10};
    target = 6;
    std::cout << searchRange(nums, target) << std::endl;

    nums = {3, 3, 3};
    target = 3;
    std::cout << searchRange(nums, target) << std::endl;

    nums = {1, 3};
    target = 1;
    std::cout << searchRange(nums, target) << std::endl;
}