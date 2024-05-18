#include <iostream>

bool isPerfectSquare(int num)
{
    int l = 1;
    int r = num;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int res = m * m;

        if (res == num)
            return true;
        else if (res < num)
            l = m + 1;
        else
            r = m - 1;
    }

    return false;
}

int main(int argc, char *argv[])
{
    int num = 16;
    std::cout << (isPerfectSquare(num) ? "True" : "False") << std::endl;

    num = 14;
    std::cout << (isPerfectSquare(num) ? "True" : "False") << std::endl;
}