#include <iostream>
#include <cmath>

// watch solution video : https://www.youtube.com/watch?v=g9YQyYi4IQQ
double recursive(double x, long n)
{
    if (n == 0)
        return 1.0;

    else if (n < 0)
    {
        n = std::abs(n);
        x = 1.0 / x;
    }

    double res;
    if (n % 2 == 0)
    {
        res = recursive(x, n / 2);
        res *= res;
    }
    else
    {
        res = recursive(x, n / 2);
        res *= res;
        res *= x;
    }

    return res;
}

double myPow(double x, long n)
{
    return recursive(x, n);
}

int main(int argc, char *argv[])
{
    double x = 2.00000, n = 10;
    std::cout << myPow(x, n) << std::endl; // 1024.0

    x = 2.10000;
    n = 3;
    std::cout << myPow(x, n) << std::endl; // 9.2610

    x = 2.00000;
    n = -2;
    std::cout << myPow(x, n) << std::endl; // 0.25
}
