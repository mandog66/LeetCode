#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int idx = std::upper_bound(letters.begin(), letters.end(), target) - letters.begin();

    return (idx >= letters.size()) ? letters[0] : letters[idx];
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