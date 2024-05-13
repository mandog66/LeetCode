#include <iostream>
#include <vector>

using std::vector;

// Watch solution video : https://www.youtube.com/watch?v=nIVW4P8b1VA
int findMin(vector<int> &nums)
{
    // 這個方法僅限於在有旋轉的陣列
    // 如果沒有旋轉直接輸出第一個元素就好(題目有規定至少旋轉一次)
    int left = 0;
    int right = nums.size() - 1;
    int res = nums[0];

    while (left <= right)
    {
        // 執行二元搜尋
        if (nums[left] < nums[right])
        {
            // 已經找到排序好的部分(可能是左或右)
            // 第一個元素一定最小，與 res 比較
            res = std::min(res, nums[left]);
            break;
        }

        int mid = (left + right) / 2;

        res = std::min(res, nums[mid]); // mid 是比較對象
        if (nums[left] <= nums[mid])
            // 左半邊是已經排序好的，所以往右找。
            // 這裡會往右找的原因是，如果 nums[mid] 大於等於 nums[left]，
            // 代表 nums[mid] 屬於左半邊的元素，
            // 而且旋轉過的陣列左半邊的所有元素會大於右半邊的所有元素，
            // 所以右半邊有最小元素。
            left = mid + 1;
        else
            // 反之
            right = mid - 1;
    }

    return res;
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