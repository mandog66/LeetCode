#include <iostream>
#include <vector>

using std::vector;

char nextGreatestLetter(vector<char> &letters, char target)
{
    if (target == 'z')
        return letters[0];

    int l = 0;
    int r = letters.size() - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (letters[m] <= target)
            l = m + 1;
        else
            r = m - 1;
    }

    return (l >= letters.size() ? letters[0] : letters[l]);
}

int main(int argc, char *argv[])
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    std::cout << nextGreatestLetter(letters, target) << std::endl; // 'c'

    letters = {'c', 'f', 'j'};
    target = 'c';
    std::cout << nextGreatestLetter(letters, target) << std::endl; // 'f'

    letters = {'x', 'x', 'y', 'y'};
    target = 'z';
    std::cout << nextGreatestLetter(letters, target) << std::endl; // 'x'
}