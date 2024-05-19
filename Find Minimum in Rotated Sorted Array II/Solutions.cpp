#include <iostream>
#include <vector>

using std::vector;

// watch solution video : https://www.youtube.com/watch?v=aCb1zKMimDQ
/*
    依照影片敘述，這題主要是去關注如果元素可以重複，從中找出最小值，時間複雜度會是怎麼被影響。

    因為元素重複，不能區分是否為已經排序。

    Ex.
        [2, 2, 2, 3, 1, 2]
        [2 ,2, 2, 2, 2, 2]
         L     M        R

        可以看到 L 等於 R，但是如果我們直接把第一個陣列當已排序，直接把第一個元素輸出就會是錯的。
        第二個陣列則是無法看出中間元素有沒有更小的元素。

    時間複雜度會因為元素重複需要區分上面的情況，所以線性搜尋還是需要的。
    最差情況下是 O(n) -> 可能 O(log n)
*/

int findMin(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (nums[l] == nums[m] && nums[m] == nums[r])
        {
            l++;
            r--;
        }
        else if (nums[m] <= nums[r])
            r = m;
        else
            l = m + 1;
    }

    return nums[l];
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 3, 5};
    std::cout << findMin(nums) << std::endl; // 1

    nums = {2, 2, 2, 0, 1};
    std::cout << findMin(nums) << std::endl; // 0
}