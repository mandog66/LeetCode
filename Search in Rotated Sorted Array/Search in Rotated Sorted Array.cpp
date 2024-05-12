#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int search(vector<int> &nums, int target)
{
    vector<int> sorted(nums.begin(), nums.end());
    std::sort(sorted.begin(), sorted.end());

    int left = 0;
    int right = sorted.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (sorted[mid] == target)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == target)
                    return i;
            }
        }
        else if (sorted[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    std::cout << search(nums, target) << std::endl; // 4

    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 3;
    std::cout << search(nums, target) << std::endl; // -1

    nums = {5, 9, 0, 1, 2};
    target = 0;
    std::cout << search(nums, target) << std::endl; // -1
}