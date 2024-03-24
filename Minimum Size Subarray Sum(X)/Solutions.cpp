class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, total = 0;
        int res = INT_MAX;

        for (int r = 0; r < nums.size(); r++)
        {
            total += nums[r];
            while (total >= target)
            {
                /*
                    這裡時間複雜度不會是 O(n ^ 2)，因為在最差的情況下 l 是 nums.size()，
                    這樣 total 會變成 0 而 target 是正整數，所以不用去考慮 while 影響時間複雜度。

                    每次只要超過 target 就會將 nums[l] 減去，此時 total 為 0
                */
                res = min(r - l + 1, res);
                total -= nums[l++];
            }
        }

        if (res == INT_MAX)
            return 0;
        else
            return res;
    }
};