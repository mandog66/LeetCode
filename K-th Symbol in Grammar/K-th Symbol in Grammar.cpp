#include <iostream>
#include <unordered_map>

using std::unordered_map;

int helper(int n, int k, unordered_map<int, std::pair<int, int>> &offset)
{
    if (n == 1)
        return 0;

    int key = helper(n - 1, k % 2 == 1 ? k / 2 + 1 : k / 2, offset);

    return k % 2 == 0 ? offset[key].second : offset[key].first;
}

int kthGrammar(int n, int k)
{
    unordered_map<int, std::pair<int, int>> offset = {{0, {0, 1}}, {1, {1, 0}}};

    return helper(n, k, offset);
}

int main(int argc, char *argv[])
{
    int n = 1;
    int k = 1;
    std::cout << kthGrammar(n, k) << std::endl; // 0

    n = 2;
    k = 1;
    std::cout << kthGrammar(n, k) << std::endl; // 0

    n = 2;
    k = 2;
    std::cout << kthGrammar(n, k) << std::endl; // 1
}