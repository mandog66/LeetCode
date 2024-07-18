#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int maxCombineArea(vector<int> &heights, int start, int mid, int end)
{
    int i = mid, j = mid + 1;
    int area = 0, h = std::min(heights[i], heights[j]);

    while (i >= start && j <= end)
    {
        // 比較區間內(start ~ end)的元素和區間內高度最矮的最大面積
        h = std::min(h, std::min(heights[i], heights[j]));
        area = std::max(area, (j - i + 1) * h);

        if (i == start)
            j++;
        else if (j == end)
            i--;
        else
        {
            if (heights[i - 1] > heights[j + 1])
                i--;
            else
                j++;
        }
    }
    return area;
}

int maxArea(vector<int> &heights, int start, int end)
{
    // divide and conquer
    // 切割剩一個元素
    if (start == end)
        return heights[start];

    int mid = start + (end - start) / 2;
    // 比較除了 heights[mid] 的兩個單獨元素
    int area = maxArea(heights, start, mid);
    area = std::max(area, maxArea(heights, mid + 1, end));
    // 必較包含 heights[mid] 區間的元素
    area = std::max(area, maxCombineArea(heights, start, mid, end));

    return area;
}

int largestRectangleArea(vector<int> &heights)
{
    if (heights.empty())
        return 0;

    return maxArea(heights, 0, heights.size() - 1);
}

int main(int argc, char *argv[])
{
    vector<int> height = {2, 1, 5, 6, 2, 3};
    std::cout << largestRectangleArea(height) << std::endl;
}