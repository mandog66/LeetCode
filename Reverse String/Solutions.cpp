#include <iostream>
#include <vector>

using std::vector;

void recursive(vector<char> &s, int left, int right)
{
    if (left >= right)
        return;

    std::swap(s[left], s[right]);
    recursive(s, left + 1, right - 1);
}

void reverseString(vector<char> &s)
{
    recursive(s, 0, s.size() - 1);
    return;
}

int main(int argc, char *argv[])
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);

    for (int i = 0; i < s.size(); i++)
        std::cout << s[i] << " ";
}