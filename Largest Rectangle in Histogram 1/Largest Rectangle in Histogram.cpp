#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int conquer(vector<int> &heights, int low, int mid, int high, int &res)
{
}

void divide(vector<int> &heights, int low, int high, int &res)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    divide(heights, low, mid, res);
    divide(heights, mid + 1, high, res);
    res = conquer(heights, low, mid, high, res);
}

int largestRectangleArea(vector<int> &heights)
{
    // int res = INT_MIN;
    // divide(heights, 0, heights.size() - 1, res);

    // return res;

    int n = heights.size();
    int res = heights[0];
    for (int i = 1; i < n; i++)
    {
        if (heights[i - 1] > heights[i])
        {
            int curDiff = heights[i] + heights[i];
            res = std::max(res, curDiff);
        }
        else if (heights[i - 1] == heights[i])
        {
            res += heights[i];
        }
        else
        {
            int curDiff = heights[i - 1] + heights[i - 1];
            res = std::max(std::max(heights[i], curDiff), res);

            if (res == heights[i] && res < heights.size() && i == heights.size() - 1 && heights[i - 1])
                res += 1;
        }
    }

    sort(heights.begin(), heights.end());
    int min = heights[0] * heights.size();

    res = std::max(min, res);

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> height = {2, 0, 2};
    std::cout << largestRectangleArea(height) << std::endl;
}