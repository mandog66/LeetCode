#include <iostream>
#include <vector>

using std::vector;
/*

題目有提到給定的已排序陣列會以未知的步數移動，所以有可能變成沒有排序的陣列。
但其實可以分成兩部分看。以 mid 為中心，將陣列分成左右兩邊，如果左半邊是未排序的狀態，那右半邊一定是排序的，反之。
接著，如果 target 在左半邊裡，這樣的話 target 會大於等於 left 而且 target 小於 mid，反之在右半邊。
如果 target 在右半邊裡，這樣的話 target 會大於 mid 而且 target 小於等於 right，反之在左半邊。
*/
int search(vector<int> &nums, int target)
{
    // 初始化
    int left = 0;
    int right = nums.size() - 1;

    // 二元搜尋法
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[left] <= nums[mid])
        {
            // 左半邊有排序
            if (target < nums[mid] && nums[left] <= target)
                right = mid - 1; // 目標在左半邊
            else
                left = mid + 1; // 目標在右半邊
        }
        else
        {
            // 右半邊有排序
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1; // 目標在右半邊
            else
                right = mid - 1; // 目標在左半邊
        }
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