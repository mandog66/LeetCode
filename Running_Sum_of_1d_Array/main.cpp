#include "Running_Sum_of_1d_Array.h"
#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
    Solution s1;
    array<int, 5> array_d = {1, 1, 1, 1, 1};
    vector<int> vector_d, vector_s;

    for (int i = 0; i < 5; i++)
    {
        vector_d.push_back(array_d[i]);
    }
    vector_s = s1.runningSum(vector_d);
    cout << "[";
    for (int i = 0; i < vector_s.size(); i++)
    {
        if (i == vector_s.size() - 1)
        {

            cout << vector_s[i];
        }
        else
        {
            cout << vector_s[i] << ", ";
        }
    }
    cout << "]";
}
