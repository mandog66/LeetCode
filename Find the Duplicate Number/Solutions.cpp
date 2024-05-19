#include <iostream>
#include <vector>

using std::vector;

// pigeon hole concept : https://builtin.com/data-science/pigeonhole-principle
/*
    這題使用二元搜尋可以利用鴿子理論解決。
    鴿子理論是說鴿子數量為 n 隻，鴿子的家有 m 個，但 n > m，所以會有一個家有兩隻個鴿子以上的數量。

    這題的 nums 就是鴿子，可以填入的數字就是鴿子的家。
    Ex.
        nums = {1, 3, 4, 2, 2}

        n = nums[0] ~ nums[4]
        m = 1 ~ 4

        如果今天我們假設家只有兩個(mid)，讓每隻鴿子住進去，但鴿子必須小於等於家，
        要是進去的鴿子數量大於家的數量，表示有重複的鴿子在前兩個家。
*/
int findDuplicate(vector<int> &nums)
{
    int l = 1;
    int r = nums.size() - 1;

    while (l < r)
    {
        int home = 0;
        int m = l + (r - l) / 2;
        for (auto pigeon : nums)
        {
            if (pigeon <= m)
                home++;
        }

        if (home > m)
            r = m;
        else
            l = m + 1;
    }

    return l;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 3, 4, 2, 2};
    std::cout << findDuplicate(nums) << std::endl; // 2

    nums = {3, 1, 3, 4, 2};
    std::cout << findDuplicate(nums) << std::endl; // 3

    nums = {3, 3, 3, 3, 3};
    std::cout << findDuplicate(nums) << std::endl; // 3
}