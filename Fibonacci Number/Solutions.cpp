#include <iostream>
#include <vector>

using std::vector;

vector<int> dp(31, -1);

int fib(int n)
{
    if (n < 2)
        return n;

    int first, second;

    // 已經計算過
    if (dp[n - 1] != -1)
        first = dp[n - 1];
    else
        first = fib(n - 1);

    // 已經計算過
    if (dp[n - 2] != -1)
        second = dp[n - 2];
    else
        second = fib(n - 2);

    return dp[n] = first + second;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 31; i++)
    {
        std::cout << fib(i) << " ";

        if (i % 5 == 0)
            std::cout << std::endl;
    }
}