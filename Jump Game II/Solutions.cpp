class Solution
{
public:
    // nums1 = {2, 3, 1, 1, 4}
    // nums2 = {1, 2, 1, 1, 1}
    int jump(vector<int> &nums)
    {
        // 比較當前元素和前一個元素可以抵達的距離大
        // 將得到的數字更新當前元素(表示可以抵達最遠距離的 index)
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = max(nums[i] + i, nums[i - 1]);
        }
        // nums1 = {2, 4, 4, 4, 8}
        // nums2 = {1, 3, 3, 4, 5}
        int ind = 0;
        int ans = 0;

        while (ind < nums.size() - 1)
        {
            ans++;
            ind = nums[ind];
        }

        return ans;
    }
};

class Solution
{
public:
    // nums = {2, 3, 1, 1, 4}
    int jump(vector<int> &nums)
    {
        int ans = 0;
        int end = 0;      // 最遠距離範圍(例如 : nums[0] = 2，代表最多跳2格，所以 end = 2)
        int farthest = 0; // 可以抵達的最遠距離

        // 將第一個元素先設為最遠距離
        // 判斷是否抵達 end ，也就是目前元素可以跳到的最後一個位置
        // 如果抵達 end 還沒有結束，代表還要再增加一步(或是想像成至少依照現在的步數是不能到達最後一個元素，所以要再增加一步)
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            farthest = max(farthest, i + nums[i]); // 可以抵達的最遠距離
            if (farthest >= nums.size() - 1)       // 判斷是否抵達最後一個元素
            {
                ++ans;
                break;
            }
            if (i == end)
            {
                ++ans;
                end = farthest;
            }
        }

        return ans;
    }
};