class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int max = nums[0];
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (*it != max)
            {
                if (count(nums.begin(), nums.end(), *it) > count(nums.begin(), nums.end(), max))
                {
                    max = *it;
                }
            }
        }
        return max;
    }
};