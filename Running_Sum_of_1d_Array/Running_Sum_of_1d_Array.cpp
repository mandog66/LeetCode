#include "Running_Sum_of_1d_Array.h"

using std::vector;

vector<int> Solution::runningSum(vector<int> &nums)
{
    vector<int> tmp(nums.size());
    for (int i = 0; i < tmp.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum += nums[j];
        }
        tmp[i] = sum;
    }
    return tmp;
}
