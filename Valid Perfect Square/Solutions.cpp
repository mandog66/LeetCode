#include <iostream>

// 這個方法是利用奇數數字相加會是完全平方數的特性
// 1 = 1
// 1 + 3 = 4
// 1 + 3 + 5 = 9
// 1 + 3 + 5 + 7 = 16
bool isPerfectSquare(int num)
{
    int i = 1;
    while (num > 0)
    {
        num -= i;
        i += 2;

        if (num == 0)
            return true;
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