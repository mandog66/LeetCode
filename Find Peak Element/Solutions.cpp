#include <iostream>
#include <vector>

using std::vector;

int findPeakElement(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] > nums[m + 1])
            r = m;
        else
            l = m + 1;
    }

    return l;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3, 1};
    std::cout << findPeakElement(nums) << std::endl; // 2

    nums = {1, 2, 1, 3, 5, 6, 4};
    std::cout << findPeakElement(nums) << std::endl; // 1 or 5
}