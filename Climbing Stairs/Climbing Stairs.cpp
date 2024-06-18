#include <iostream>
#include <unordered_map>

using std::unordered_map;

void helper(int n, int &res, unordered_map<int, int> &map)
{
    if (n == 0)
    {
        res++;
        return;
    }

    if (map.find(n) != map.end())
    {
        res += map[n];
        return;
    }

    if (n < 0)
        return;

    helper(n - 1, res, map);
    helper(n - 2, res, map);
    map[n] = res;
}

int climbStairs(int n)
{
    unordered_map<int, int> map;
    int res = 0;

    helper(n - 1, res, map);
    helper(n - 2, res, map);

    return res;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i <= 45; i++)
    {
        std::cout << climbStairs(i) << " ";

        if (i % 9 == 0)
            std::cout << std::endl;
    }
}