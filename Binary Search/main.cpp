#include <iostream>
#include <vector>

using std::vector;

int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (nums[mid] == target)
            return mid;

        if (target > nums[mid])
        {
            left = mid + 1;
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    std::cout << search(nums, target) << std::endl; // 4

    nums = {-1, 0, 3, 5, 9, 12};
    target = 2;
    std::cout << search(nums, target) << std::endl; // -1

    nums = {5};
    target = 5;
    std::cout << search(nums, target) << std::endl; // 0

    nums = {2, 5};
    target = 5;
    std::cout << search(nums, target) << std::endl; // 1
}