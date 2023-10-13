class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        // Example : nums = {1, 2, 3, 4, 5, 6, 7}, k = 3
        // no matter what k is equal to, k is equivalent to k.nums.size()
        k = k % nums.size();
        // nums = {4, 3, 2, 1, 5, 6, 7}
        reverse(nums.begin(), nums.begin() + (nums.size() - k));
        // nums = {4, 3, 2, 1, 7, 6, 5}
        reverse(nums.begin() + (nums.size() - k), nums.end());
        // nums = {5, 6, 7, 1, 2, 3, 4}
        reverse(nums.begin(), nums.end());
    }
};