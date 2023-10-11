#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int m = 1; // the number of elements in nums1
    int n = 5; // the number of elements in nums2

    int i = m - 1;     // 指到nums1非0元素的最後一個
    int j = n - 1;     // 指到nums2最後一個元素
    int k = m + n - 1; // 指到要將最大元素放在nums1的位置

    vector<int> nums1 = {4, 0, 0, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3, 5, 6};

    // 透過指標的移動，將元素放到陣列中
    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    // 輸出陣列
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
}