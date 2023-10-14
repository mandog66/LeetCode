class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int count = 1;
        bool path = false;

        if (nums.size() == 1)
        {
            cout << "true" << endl;
            return true;
        }
        for (int i = nums.size() - 2; i <= nums.size() - 1; i--)
        {
            if (nums[i] < count)
            {
                count++;
                path = false;
            }
            else
            {
                count = 1;
                path = true;
            }
        }

        cout << (path ? "true" : "false") << endl;
        return path;
    }
};