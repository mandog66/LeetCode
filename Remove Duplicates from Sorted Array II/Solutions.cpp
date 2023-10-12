class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (auto ele : nums)
        {
            // 前兩個元素不管如何都可以直接填進去
            if (i == 0 || i == 1 || nums[i - 2] != ele)
            {
                nums[i] = ele;
                i++;
            }
        }
        return i;
    }
};