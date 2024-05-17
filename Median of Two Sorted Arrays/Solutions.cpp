#include <iostream>
#include <vector>

using std::vector;

// watch solution video : https://www.youtube.com/watch?v=q6IEA26hvXc

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> A;
    vector<int> B;

    if (nums1.size() > nums2.size())
    {
        A = nums2;
        B = nums1;
    }
    else
    {
        A = nums1;
        B = nums2;
    }

    int total = A.size() + B.size();
    int half = total / 2;
    int l = 0, r = A.size() - 1;

    while (true)
    {
        int AM = (l + r < 0 ? -1 : (l + r) / 2); // A的比較對象
        int BM = half - AM - 2;                  // B的比較對象

        // 找到A部分正確的中間元素
        // AM 有可能超出範圍，如果是 AL 超出範圍表示 AM < 0; 如果是 AR 超出範圍表示 AM + 1 >= A.size()
        int AL = (AM >= 0 ? A[AM] : INT_MIN);
        int AR = ((AM + 1) < A.size() ? A[AM + 1] : INT_MAX);

        // 找到B部分正確的中間元素
        // BM 有可能超出範圍，如果是 BL 超出範圍表示 BM < 0; 如果是 BR 超出範圍表示 BM + 1 >= B.size()
        int BL = (BM >= 0 ? B[BM] : INT_MIN);
        int BR = ((BM + 1) < B.size() ? B[BM + 1] : INT_MAX);

        // A部分和B部分都合法
        if (AL <= BR && BL <= AR)
        {
            // 元素個數為奇數個
            if (total % 2)
                return std::min(AR, BR);
            // 元素個數為偶數個
            else
                return (std::max(AL, BL) + std::min(AR, BR)) / 2.0;
        }
        // A部份太多元素
        else if (AL > BR)
            r = AM - 1;
        // A部份太少元素
        else
            l = AM + 1;
    }
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
}