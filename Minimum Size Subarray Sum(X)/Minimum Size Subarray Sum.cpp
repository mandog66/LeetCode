/*
    I didn't get it.(See Solutions.cpp)

    It's fine!

    Keep going!
*/

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int l = 0, total = 0;
    int res = INT_MAX;

    for (int r = 0; r < nums.size(); r++)
    {
        total += nums[r];
        while (total >= target)
        {
            res = min(r - l + 1, res);
            total -= nums[l++];
        }
    }

    if (res == INT_MAX)
        return 0;
    else
        return res;
}

int main()
{
    // int target = 7;
    // vector<int> nums = {2, 3, 1, 2, 4, 3};
    // cout << minSubArrayLen(target, nums) << endl; // 2

    // int target = 4;
    // vector<int> nums = {1, 4, 4};
    // cout << minSubArrayLen(target, nums) << endl; // 1

    // int target = 11;
    // vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    // cout << minSubArrayLen(target, nums) << endl; // 0

    int target = 213;
    vector<int> nums = {12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
    cout << minSubArrayLen(target, nums) << endl; // 8

    // int target = 9;
    // vector<int> nums = {1, 2, 2, 2, 2, 4};
    // cout << minSubArrayLen(target, nums) << endl; // 5
}
