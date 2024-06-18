#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

// Memoization
int climbStairs_Memoization(int n, unordered_map<int, int> &map)
{
    if (n == 0 || n == 1)
        return 1;

    if (map.find(n) == map.end())
        map[n] = climbStairs_Memoization(n - 1, map) + climbStairs_Memoization(n - 2, map);

    return map[n];
}

// DP
int climbStairs_Tabulation(int n)
{
    if (n == 0 || n == 1)
        return 1;

    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;

    for (int i = 2; i < n + 1; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main(int argc, char *argv[])
{
    unordered_map<int, int> map;

    std::cout << "climbStairs_Memoization : " << std::endl;
    for (int i = 1; i <= 45; i++)
    {
        std::cout << climbStairs_Memoization(i, map) << " ";

        if (i % 9 == 0)
            std::cout << std::endl;
    }

    std::cout << "\nclimbStairs_Tabulation : " << std::endl;
    for (int i = 1; i <= 45; i++)
    {
        std::cout << climbStairs_Tabulation(i) << " ";

        if (i % 9 == 0)
            std::cout << std::endl;
    }
}