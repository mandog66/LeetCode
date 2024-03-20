/*
    I didn't get it.(See Solutions.cpp)

    Hang in there!

    I have faith in you!
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    vector<int> res;
    const int rows = mat.size();
    const int cols = mat[0].size();

    bool going_up = true;
    int cur_rows = 0;
    int cur_cols = 0;

    while (res.size() != rows * cols)
    {
        if (going_up)
        {
            while (cur_rows >= 0 && cur_cols < cols)
            {
                res.push_back(mat[cur_rows][cur_cols]);

                cur_rows -= 1;
                cur_cols += 1;
            }

            if (cur_cols == cols)
            {
                cur_cols -= 1;
                cur_rows += 2;
            }
            else
            {
                cur_rows += 1;
            }

            going_up = false;
        }
        else
        {
            while (cur_rows < rows && cur_cols >= 0)
            {
                res.push_back(mat[cur_rows][cur_cols]);

                cur_rows += 1;
                cur_cols -= 1;
            }

            if (cur_rows == rows)
            {
                cur_rows -= 1;
                cur_cols += 2;
            }
            else
            {
                cur_cols += 1;
            }

            going_up = true;
        }
    }

    return res;
}

ostream &operator<<(ostream &out, const vector<int> &nums)
{
    const int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        out << nums[i] << " ";
    }

    return out;
}

ostream &operator<<(ostream &out, const vector<vector<int>> &mat)
{
    const int n = mat.size();
    const int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            out << mat[i][j] << " ";
        }

        out << endl;
    }

    return out;
}

int main()
{
    // vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    // vector<int> nums2 = {1, 2, 3};
    // vector<int> nums3 = {2, 1, -1};

    // cout << pivotIndex(nums1) << endl; // return 3
    // cout << pivotIndex(nums2) << endl; // return -1
    // cout << pivotIndex(nums3) << endl; // return 0

    // vector<int> nums2 = {3, 6, 1, 0};
    // vector<int> nums3 = {1, 2, 3, 4};

    // cout << dominantIndex(nums2) << endl; // return 1
    // cout << dominantIndex(nums3) << endl; // return -1

    // vector<int> nums1 = {1, 2, 3};
    // vector<int> nums2 = {4, 3, 2, 1};
    // vector<int> nums3 = {9};

    // cout << plusOne(nums1) << endl; // return 1, 2, 4
    // cout << plusOne(nums2) << endl; // return 4, 3, 2, 1
    // cout << plusOne(nums3) << endl; // return 1, 0

    // vector<vector<int>> mat = {{1}};
    // vector<vector<int>> mat = {{1, 2, 3}};
    // vector<vector<int>> mat = {{1}, {4}, {7}};
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << findDiagonalOrder(mat);
}
