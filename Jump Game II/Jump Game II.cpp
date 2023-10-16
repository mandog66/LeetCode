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

using namespace std;

int minimum_step(vector<int> nums)
{
    int furthest = 0;
    int end = 0;
    int step = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        furthest = max(furthest, i + nums[i]);

        if (furthest >= nums.size() - 1)
        {
            ++step;
            break;
        }

        if (i == end)
        {
            ++step;
            end = furthest;
        }
    }
    cout << "Minimum step : ";
    cout << step << endl;
}

int main()
{
    // vector<int> nums = {2, 3, 1, 1, 4};
    // vector<int> nums = {2, 3, 0, 1, 4};
    // vector<int> nums = {2, 0, 0};
    // vector<int> nums = {0};
    // vector<int> nums = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
    // vector<int> nums = {2, 5, 0, 1, 4};
    // vector<int> nums = {1, 2, 3, 4, 5};
    // vector<int> nums = {2, 3, 0, 0, 0};
    vector<vector<int>> nums = {{2, 3, 1, 1, 4}, {2, 3, 0, 1, 4}, {2, 0, 0}, {0}, {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0}, {2, 5, 0, 1, 4}, {1, 2, 3, 4, 5}, {2, 3, 0, 0, 0}};

    for (int i = 0; i < nums.size(); i++)
    {
        minimum_step(nums[i]);
    }
}
