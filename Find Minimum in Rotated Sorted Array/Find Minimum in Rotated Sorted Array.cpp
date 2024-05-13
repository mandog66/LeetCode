#include <iostream>
#include <vector>

using std::vector;

int findMin(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (r - l == 1)
            return (nums[l] > nums[r] ? nums[r] : nums[l]);

        if (nums[m] < nums[r])
            r = m;
        else
            l = m;
    }

    return nums[l];
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3, 4, 5, 1, 2};
    std::cout << findMin(nums) << std::endl; // 1

    nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << findMin(nums) << std::endl; // 0

    nums = {11, 13, 15, 17};
    std::cout << findMin(nums) << std::endl; // 11
}