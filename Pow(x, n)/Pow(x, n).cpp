#include <iostream>
#include <cmath>

double myPow(double x, double n)
{
    if (n < 0)
    {
        double _x = 1.0 / x;
        double _n = -n;
        return std::pow(_x, _n);
    }
    else
    {
        return std::pow(x, n);
    }
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
