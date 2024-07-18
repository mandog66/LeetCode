#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct SegTreeNode
{
    int start;
    int end;
    int min;

    SegTreeNode *left;
    SegTreeNode *right;
    SegTreeNode(int start, int end)
    {
        this->start = start;
        this->end = end;
        left = right = nullptr;
    }
};

// 參考 : https://www.geeksforgeeks.org/segment-tree-data-structure/
SegTreeNode *buildSegmentTree(vector<int> &heights, int start, int end)
{
    // 建立樹
    // 元素包含一個區段和這個區段高度最矮的 index
    SegTreeNode *root = new SegTreeNode(start, end);

    if (start == end)
    {
        root->min = start;
        return root;
    }
    else
    {
        int mid = start + (end - start) / 2;
        root->left = buildSegmentTree(heights, start, mid);
        root->right = buildSegmentTree(heights, mid + 1, end);
        root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;

        return root;
    }
}

int query(vector<int> &heights, SegTreeNode *root, int start, int end)
{
    if (!root || root->start > end || root->end < start)
        return -1;

    if (root->start >= start && root->end <= end)
        return root->min;

    int leftMin = query(heights, root->left, start, end);
    int rightMin = query(heights, root->right, start, end);

    if (leftMin == -1)
        return rightMin;

    if (rightMin == -1)
        return leftMin;

    return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
}

int calculateMax(vector<int> &heights, SegTreeNode *root, int start, int end)
{
    // 找到區間內面積最大的方形
    if (start > end)
        return -1;

    if (start == end)
        return heights[start];

    // 找到這個區間內高度最矮的 index
    int minidx = query(heights, root, start, end);
    // 依照 minIdx 分成左右兩邊，分別計算區間內面積最大的方形
    int leftMax = calculateMax(heights, root, start, minidx - 1);
    int rightMax = calculateMax(heights, root, minidx + 1, end);
    int minMax = heights[minidx] * (end - start + 1);

    return std::max(std::max(leftMax, rightMax), minMax);
}

int largestRectangleArea(vector<int> &heights)
{
    if (heights.size() == 0)
        return 0;

    SegTreeNode *root = buildSegmentTree(heights, 0, heights.size() - 1);

    return calculateMax(heights, root, 0, heights.size() - 1);
}

int main(int argc, char *argv[])
{
    vector<int> height = {2, 1, 5, 6, 2, 3};
    std::cout << largestRectangleArea(height) << std::endl;
}