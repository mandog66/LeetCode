/*
    I didn't get it.(See Solutions.cpp)

    It's fine!

    Keep going!
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <cstdlib>
#include <time.h>
#include <unordered_map>
#include <array>

using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    int lpos = 0;
    int rpos = n - 1;
    int lmax = height[lpos];
    int rmax = height[rpos];
    int res = 0;

    while (lpos < rpos)
    {
        if (lmax <= rmax)
        {
            lpos += 1;
            lmax = max(lmax, height[lpos]);
            res += (lmax - height[lpos]);
        }
        else
        {
            rpos -= 1;
            rmax = max(rmax, height[rpos]);
            res += (rmax - height[rpos]);
        }
    }

    return res;
}

int main()
{
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // return 6
    vector<int> height = {4, 2, 0, 3, 2, 5}; // return 9
    // vector<int> height = {0, 2, 0}; // return 0
    // vector<int> height = {4, 2, 3}; // return 1
    cout << trap(height) << endl;
}
