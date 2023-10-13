class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> tmp(nums.size());

        if (nums.size() == k)
        {
        }
        else if (nums.size() < k)
        {
            while (k > nums.size())
            {
                k = k - nums.size();
            }
            for (int i = 0; i < nums.size(); i++)
            {
                if (i + k <= nums.size() - 1)
                {
                    tmp[i + k] = nums[i];
                }
                else
                {
                    tmp[k - (nums.size() - i)] = nums[i];
                }
            }
            tmp.swap(nums);
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (i + k <= nums.size() - 1)
                {
                    tmp[i + k] = nums[i];
                }
                else
                {
                    tmp[k - (nums.size() - i)] = nums[i];
                }
            }
            tmp.swap(nums);
        }
    }
};