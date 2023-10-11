#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int k = 0;
        vector<int> tmp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                k++;
                tmp.push_back(nums[i]);
            }
        }
        nums.swap(tmp);
        return k;
    }
};