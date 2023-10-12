class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int m = 1, n = 0; // m is number of unique element, n is the index of the unique element put in
        for (int i = 0; i < nums.size(); i++)
        {

            if (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                m++;
            }
            else
            {
                if (m >= 2)
                {
                    nums[n++] = nums[i];
                    nums[n++] = nums[i];
                    m = 1;
                }
                else
                {
                    m = 1;
                    nums[n++] = nums[i];
                }
            }
        }
        return n;
    }
};