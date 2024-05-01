#include <iostream>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;

// 參考影片 : https://www.youtube.com/watch?v=r6Wz4W1TbuI
/************************* DP(Dynamic Programming) *************************/
int findTargetSumWays_DP(std::vector<int> &nums, int target)
{
    const int n = nums.size();
    const int sum = std::accumulate(nums.begin(), nums.end(), 0);

    if (sum < std::abs(target))
        return 0;

    int offset = sum;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(sum + offset + 1, 0));
    dp[0][offset] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = nums[i]; j < (2 * sum + 1) - nums[i]; j++)
        {
            if (dp[i][j])
            {
                dp[i + 1][j + nums[i]] += dp[i][j];
                dp[i + 1][j - nums[i]] += dp[i][j];
            }
        }
    }

    return dp.back()[sum + target];
}
/************************* DP(Dynamic Programming) *************************/

/************************* DFS *************************/
void DFS(std::vector<int> &nums, int d, int target, int &res)
{
    if (d == nums.size())
    {
        if (target == 0)
            res++;

        return;
    }

    DFS(nums, d + 1, target - nums[d], res);
    DFS(nums, d + 1, target + nums[d], res);
}
int findTargetSumWays_DFS(std::vector<int> &nums, int target)
{
    int sum = std::accumulate(nums.begin(), nums.end(), 0);

    if (sum < std::abs(target))
        return 0;

    int res = 0;
    DFS(nums, 0, target, res);

    return res;
}
/************************* DFS *************************/

int main()
{
    int target = 3;
    std::vector<int> nums = {1, 1, 1, 1, 1};
    cout << findTargetSumWays_DFS(nums, target) << endl; // 5

    target = 1;
    nums = {1};
    cout << findTargetSumWays_DFS(nums, target) << endl; // 1

    target = 3;
    nums = {1, 1, 1, 1, 1};
    cout << findTargetSumWays_DP(nums, target) << endl; // 5

    target = 1;
    nums = {1};
    cout << findTargetSumWays_DP(nums, target) << endl; // 1
}