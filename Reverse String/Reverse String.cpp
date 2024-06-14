#include <iostream>
#include <vector>

using std::vector;

void recursive(vector<char> &s, vector<char> &res, int n)
{
    if (n >= s.size())
        return;

    recursive(s, res, n + 1);
    s[res.size() - n - 1] = res[n];
}

void reverseString(vector<char> &s)
{
    vector<char> res(s.begin(), s.end());
    recursive(s, res, 0);
    return;
}

int main(int argc, char *argv[])
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);

    for (int i = 0; i < s.size(); i++)
        std::cout << s[i] << " ";
}