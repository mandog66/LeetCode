class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 0; // represents the index of the unique element put in
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[k] != nums[i])
            {
                nums[k + 1] = nums[i];
                k++;
            }
        }
        return k + 1;
    }
};