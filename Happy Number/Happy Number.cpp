#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool isHappy(int n)
{
    if (n == 1)
        return true;

    unordered_set<int> hashset;
    bool keep = true;

    while (keep)
    {
        int total = 0;
        while (n != 0)
        {
            int d = n % 10;
            d = d * d;
            total += d;
            n = n / 10;
        }

        if (total == 1)
            return true;
        else
        {
            if (hashset.count(total) <= 0)
            {
                hashset.insert(total);
                keep = true;
            }
            else
                keep = false;
            n = total;
        }
    }

    return false;
}

int main()
{
    int n = 19;
    string res = isHappy(n) ? "true" : "false";
    cout << res << endl;

    n = 7;
    res = isHappy(n) ? "true" : "false";
    cout << res << endl;
}
