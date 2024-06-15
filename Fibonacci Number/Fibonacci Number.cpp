#include <iostream>
#include <unordered_map>
#include <chrono>

using std::unordered_map;
using namespace std::chrono;

unordered_map<int, int> map;

int fib(int n)
{
    int res = -1;
    if (n < 2)
        return n;

    if (map.find(n) != map.end())
        return map[n];

    res = fib(n - 1) + fib(n - 2);
    map[n] = res;

    return res;

    // if (n < 2)
    //     return n;

    // return fib(n - 1) + fib(n - 2);
}

int main(int argc, char *argv[])
{
    auto start = high_resolution_clock::now();
    for (int i = 1; i <= 35; i++)
    {
        std::cout << fib(i - 1) << " ";

        if (i % 5 == 0)
            std::cout << std::endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << std::endl;
    std::cout << duration.count() << std::endl;
}