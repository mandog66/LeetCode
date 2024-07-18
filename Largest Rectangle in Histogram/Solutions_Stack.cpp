#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using std::stack;
using std::vector;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    // 這是為了將剩餘在推疊中的元素全部判斷完
    heights.push_back(0);
    int res = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            // 當遇到比堆疊頂部小的元素後為了要保持階梯(遞增)形式要進行整理(找出最大面積)
            // 包持階梯(遞增)形式是讓我們方便判斷多個元素和在一起的最大面積，
            // 因為是遞增所以前面的元素會比目前元素小，把前一個元素當作長，
            // 那寬就會是前一個元素到目前元素的距離，相乘即為當前元素能得到的最大面積
            int top = heights[st.top()]; // 目前元素
            st.pop();
            int ran = st.empty() ? -1 : st.top(); // 之前的元素
            // (i - ran - 1) 就是"寬"
            // i 是遇到比堆疊頂端小的元素位置
            // -1 表示去掉 i 這個元素
            res = std::max(res, top * (i - ran - 1)); // 找到最大面積
        }

        // 元素放入堆疊後會像是階梯一樣，以遞增的形式出現
        st.push(i);
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> height = {2, 1, 5, 6, 2, 3};
    std::cout << largestRectangleArea(height) << std::endl;
}