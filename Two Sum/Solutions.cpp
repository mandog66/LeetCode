class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = target - nums[i];

            if (hashmap.count(num))
                return {hashmap[num], i};

            hashmap[nums[i]] = i;
        }

        return {};
    }
};