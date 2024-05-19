#include <iostream>
#include <vector>

using std::vector;

int findMin(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    int res = nums[0];

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (nums[l] < nums[r])
        {
            res = std::min(res, nums[l]);
            break;
        }

        res = std::min(res, nums[m]);
        if (nums[l] == nums[m])
            l = l + 1;
        else if (nums[l] < nums[m])
            l = m + 1;
        else
            r = m - 1;
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 3, 5};
    std::cout << findMin(nums) << std::endl; // 1

    nums = {2, 2, 2, 0, 1};
    std::cout << findMin(nums) << std::endl; // 0
}