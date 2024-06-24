#include <iostream>

int kthGrammar(int n, int k)
{
    if (n == 1)
        return 0;

    // length = 1 * (2 ^ n)
    int length = 1 << (n - 2);

    /*
        如果是 n 列的 kth(1 ~ k / 2) 元素，那會對應 n - 1 列的 kth 元素;
        如果是 n 列的 kth(k / 2 + 1 ~ k) 元素，那會對應 n - 1 列的 kth 元素的對立元素;
    */
    if (k <= length)
        return kthGrammar(n - 1, k);
    else
        return 1 - kthGrammar(n - 1, k - length);
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