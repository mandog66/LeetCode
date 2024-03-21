/*
    I didn't get it.(See Solutions.cpp)

    It's fine!

    Keep going!
*/

#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &nums)
{
    const int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        out << nums[i] << " ";
    }

    return out;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int left = 0, right = matrix[0].size();
    int top = 0, bottom = matrix.size();

    while (left < right && top < bottom)
    {
        for (int _left = left; _left < right; _left++)
        {
            res.push_back(matrix[top][_left]);
        }

        top += 1;

        for (int _top = top; _top < bottom; _top++)
        {
            res.push_back(matrix[_top][right - 1]);
        }

        right -= 1;

        if (top == bottom || left == right)
            break;

        for (int _right = right - 1; _right >= left; _right--)
        {
            res.push_back(matrix[bottom - 1][_right]);
        }

        bottom -= 1;

        for (int _bottom = bottom - 1; _bottom >= top; _bottom--)
        {
            res.push_back(matrix[_bottom][left]);
        }

        left += 1;
    }

    return res;
}

int main()
{
    int res;

    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << spiralOrder(mat); // 1, 2, 3, 6, 9, 8, 7, 4, 5

    // vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // cout << spiralOrder(mat); // 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7

    // vector<vector<int>> mat = {{1}};
    // cout << spiralOrder(mat); // 1, 2, 3, 6, 9, 8, 7, 4, 5
}
