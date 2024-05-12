#include <iostream>
#include <vector>

using std::vector;

int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;

    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {
        if (nums[l] > nums[l + 1])
            return l;
        else if (nums[r] > nums[r - 1])
            return r;
        else
        {
            l += 1;
            r -= 1;
        }
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